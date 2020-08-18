#ifdef PAGED_ATTRIB

#undef dGetByte
#undef dGetWord
#undef dPutByte
#undef dPutWord
#undef dPutWordAligned
#undef dGetWordAligned

#define dGetByte(x) (GetByte(x))

#define dPutByte(x,y) (PutByte(x,y))

#define dGetWord(x) (GetByte(x)|(GetByte(x+1)<<8))
#define dGetWordAligned(x) (dGetWord(x))

#endif

