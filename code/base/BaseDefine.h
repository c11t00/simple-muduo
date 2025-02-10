typedef unsigned char BYTE;
typedef signed short SWORD;
typedef unsigned short WORD;
typedef signed int SDWORD;
typedef unsigned int DWORD;

#ifdef __APPLE__
typedef signed long long SQWORD;
typedef unsigned long long QWORD;
#else
typedef signed long SQWORD;
typedef unsigned long QWORD;
#endif
