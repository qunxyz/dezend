/*
///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   zend_dump.h
//  Version     :   1.0
//  Creator     :   RM
//  Create Date :   2006-01-01
//  Comment     :
//
///////////////////////////////////////////////////////////////////////////////
*/

#ifndef __ZEND_DUMP_H__
#define __ZEND_DUMP_H__

#ifdef __cplusplus
extern "C"
{
#endif

/*
///////////////////////////////////////////////////////////////////////////////
// D E F I N E S
///////////////////////////////////////////////////////////////////////////////
*/
#ifndef HEAP_ALLOC
#define HEAP_ALLOC( Size ) HeapAlloc( GetProcessHeap( ), 0, Size )
#endif

#ifndef HEAP_FREE
#define HEAP_FREE( Buffer ) HeapFree( GetProcessHeap( ), 0, Buffer )
#endif

#ifndef HEAP_REALLOC
#define HEAP_REALLOC( Buffer, Size ) HeapReAlloc( GetProcessHeap( ), 0, Buffer, Size )
#endif

#ifdef LIB_EXPORTS
#define DUMP_API __declspec( dllexport )
#else
#define DUMP_API
#endif

/*
///////////////////////////////////////////////////////////////////////////////
// S T R U C T U R E S
///////////////////////////////////////////////////////////////////////////////
*/
typedef struct _OPCODE_TABLE {
    TCHAR OpName[32];
    TCHAR Op[12];
    ULONG Flags;
} OPCODE_TABLE, *POPCODE_TABLE;

/*
///////////////////////////////////////////////////////////////////////////////
// G L O B A L S
///////////////////////////////////////////////////////////////////////////////
*/
extern OPCODE_TABLE g_OpTableArray[];
extern TCHAR g_OpTypeArray[][16];
extern TCHAR g_DataTypeArray[][16];

/*
///////////////////////////////////////////////////////////////////////////////
// F U N C T I O N S
///////////////////////////////////////////////////////////////////////////////
*/

/*
///////////////////////////////////////////////////////////////////////////////
// Init
///////////////////////////////////////////////////////////////////////////////
*/
void DUMP_API Init( );

/*
///////////////////////////////////////////////////////////////////////////////
// Uninit
///////////////////////////////////////////////////////////////////////////////
*/
void DUMP_API Uninit( );

/*
///////////////////////////////////////////////////////////////////////////////
// pre_compile
///////////////////////////////////////////////////////////////////////////////
*/
void pre_compile( );

/*
///////////////////////////////////////////////////////////////////////////////
// post_execute
///////////////////////////////////////////////////////////////////////////////
*/
void post_execute( );

/*
///////////////////////////////////////////////////////////////////////////////
// dump_op_array
///////////////////////////////////////////////////////////////////////////////
*/
void dump_op_array( PVOID OpArray, ULONG Indent );

/*
///////////////////////////////////////////////////////////////////////////////
// dump_op_array_ex
///////////////////////////////////////////////////////////////////////////////
*/
void dump_op_array_ex( PVOID OpArray, ULONG Indent, ULONG State );

#ifdef __cplusplus
}
#endif
/*
///////////////////////////////////////////////////////////////////////////////
// E N D  O F  F I L E
///////////////////////////////////////////////////////////////////////////////
*/
#endif /* __ZEND_DUMP_H__ */