#include "mouse.h"

int hook_id_mouse = 3;        
struct packet mouse_packet;   
uint8_t byte_index = 0, mouse_bytes[3], current_byte;         

int (mouse_subscribe_int)(uint8_t *bit_no){
  if (bit_no == NULL) return 1;
  *bit_no = BIT(hook_id_mouse);
  return sys_irqsetpolicy(IRQ_MOUSE, IRQ_REENABLE | IRQ_EXCLUSIVE, &hook_id_mouse);
}

int (mouse_unsubscribe_int)(){
  return sys_irqrmpolicy(&hook_id_mouse);
}

void (mouse_ih)(){
  if(read_KBC_output(KBC_WRITE_CMD, &current_byte, 1)) printf("Error in reading byte from mouse\n");
}

void mouse_sync_bytes() {
  if (byte_index == 0 && (current_byte & FIRST_BYTE)) { 
    mouse_bytes[byte_index]= current_byte;
    byte_index++;
  }
  else if (byte_index > 0) {                            
    mouse_bytes[byte_index] = current_byte;
    byte_index++;
  }
}

void (mouse_bytes_to_packet)(){

  for (int k = 0 ; k < 3 ; k++) {
    mouse_packet.bytes[k] = mouse_bytes[k];
  }

  mouse_packet.lb = mouse_bytes[0] & MOUSE_LB;
  mouse_packet.mb = mouse_bytes[0] & MOUSE_MB;
  mouse_packet.rb = mouse_bytes[0] & MOUSE_RB;
  mouse_packet.x_ov = mouse_bytes[0] & MOUSE_X_OVERFLOW;
  mouse_packet.y_ov = mouse_bytes[0] & MOUSE_Y_OVERFLOW;
  mouse_packet.delta_x = (mouse_bytes[0] & MOUSE_X_SIGNAL) ? (0xFF00 | mouse_bytes[1]) : mouse_bytes[1];
  mouse_packet.delta_y = (mouse_bytes[0] & MOUSE_Y_SIGNAL) ? (0xFF00 | mouse_bytes[2]) : mouse_bytes[2];
  
}


int (mouse_write)(uint8_t command) {

  uint8_t attempts = MAX_ATTEMPS;
  uint8_t mouse_response;

  do {
    attempts--;
    if (write_KBC_command(KBC_IN_CMD, WRITE_BYTE_MOUSE)) return 1;
    if (write_KBC_command(KBC_OUT_CMD, command)) return 1;
    tickdelay(micros_to_ticks(WAIT_KBC));
    if (util_sys_inb(KBC_OUT_CMD, &mouse_response)) return 1;
    if (mouse_response == ACK) return 0;
  } while (mouse_response != ACK && attempts);

  return 1;
}
