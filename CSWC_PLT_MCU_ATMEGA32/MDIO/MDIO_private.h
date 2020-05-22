#ifndef MDIO_PRIVATE
#define MDIO_PRIVATE

#define conc(b7,b6,b5,b4,b3,b2,b1,b0) conchelper(b7,b6,b5,b4,b3,b2,b1,b0)
#define conchelper(x7,x6,x5,x4,x3,x2,x1,x0)  0b##x7##x6##x5##x4##x3##x2##x1##x0


#endif
