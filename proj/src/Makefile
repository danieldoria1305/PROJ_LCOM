.PATH: ${.CURDIR}/controller
.PATH: ${.CURDIR}/devices
.PATH: ${.CURDIR}/model
.PATH: ${.CURDIR}/view
.PATH: ${.CURDIR}/controller/collisionsController
.PATH: ${.CURDIR}/controller/gameController
.PATH: ${.CURDIR}/controller/ghostsController
.PATH: ${.CURDIR}/controller/keyboardController
.PATH: ${.CURDIR}/controller/mouseController
.PATH: ${.CURDIR}/controller/pacmanController
.PATH: ${.CURDIR}/controller/timerController
.PATH: ${.CURDIR}/devices/graphics
.PATH: ${.CURDIR}/devices/kbc
.PATH: ${.CURDIR}/devices/kbc/keyboard
.PATH: ${.CURDIR}/devices/kbc/mouse
.PATH: ${.CURDIR}/devices/timer
.PATH: ${.CURDIR}/devices/rtc
.PATH: ${.CURDIR}/devices/utils
.PATH: ${.CURDIR}/model/coinsModel
.PATH: ${.CURDIR}/model/ghostsModel
.PATH: ${.CURDIR}/model/pacmanModel
.PATH: ${.CURDIR}/view/coinsView
.PATH: ${.CURDIR}/view/ghostsView
.PATH: ${.CURDIR}/view/menuView
.PATH: ${.CURDIR}/view/mouseView
.PATH: ${.CURDIR}/view/pacmanView
.PATH: ${.CURDIR}/view/pixmaps
.PATH: ${.CURDIR}/view/finalScoreView
.PATH: ${.CURDIR}/view/scoreView
.PATH: ${.CURDIR}/view/timerView
.PATH: ${.CURDIR}/view/wallsView

# name of the program (Minix service)
PROG=proj

# source code files to be compiled
SRCS = proj.c collisionsController.c gameController.c ghostsController.c keyboardController.c mouseController.c pacmanController.c timerController.c graphics.c keyboard.c mouse.c timer.c rtc.c coin.c ghost.c pacman.c utils.c coinsView.c ghostsView.c menuView.c mouseView.c pacmanView.c  pixmaps.c finalScoreView.c scoreView.c timerView.c wallsView.c

# additional compilation flags
# "-Wall -Wextra -Werror -I . -std=c11 -Wno-unused-parameter" are already set
CFLAGS += -pedantic -D__LCOM_OPTIMIZED__

# list of library dependencies (for Lab 2, only LCF library)
DPADD += ${LIBLCF}
LDADD += -llcf

# include LCOM's makefile that does all the "heavy lifting"
.include <minix.lcom.mk>
