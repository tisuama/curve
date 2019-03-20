/* Created by "go tool cgo" - DO NOT EDIT. */

/* package command-line-arguments */


#line 1 "cgo-builtin-prolog"

#include <stddef.h> /* for ptrdiff_t below */

#ifndef GO_CGO_EXPORT_PROLOGUE_H
#define GO_CGO_EXPORT_PROLOGUE_H

typedef struct { const char *p; ptrdiff_t n; } _GoString_;

#endif

/* Start of preamble from import "C" comments.  */


#line 3 "/home/lixiaocui1/Project/go/src/wrappertoc/Test4/etcdclient.go"

#include <stdlib.h>

enum EtcdErrCode
{
    // grpc errCode, 具体的含义见:
    // https://godoc.org/go.etcd.io/etcd/etcdserver/api/v3rpc/rpctypes#ErrGRPCNoSpace
    // https://godoc.org/google.golang.org/grpc/codes#Code
    OK = 0,
    Canceled,
    Unknown,
    InvalidArgument,
    DeadlineExceeded,
    NotFound,
    AlreadyExists,
    PermissionDenied,
    ResourceExhausted,
    FailedPrecondition,
    Aborted,
    OutOfRange,
    Unimplemented,
    Internal,
    Unavailable,
    DataLoss,
    Unauthenticated,

    // 自定义错误码
    TxnUnkownOp,
    ObjectNotExist,
    ErrObjectType,
    KeyNotExist,
};

enum OpType {
  OpPut = 1,
  OpDelete = 2
};

struct EtcdConf {
    char *Endpoints;
    int len;
    int DialTimeout;
};

struct Operation {
    enum OpType opType;
    char *key;
    char *value;
    int keyLen;
    int valueLen;
};

#line 1 "cgo-generated-wrapper"


/* End of preamble from import "C" comments.  */


/* Start of boilerplate cgo prologue.  */
#line 1 "cgo-gcc-export-header-prolog"

#ifndef GO_CGO_PROLOGUE_H
#define GO_CGO_PROLOGUE_H

typedef signed char GoInt8;
typedef unsigned char GoUint8;
typedef short GoInt16;
typedef unsigned short GoUint16;
typedef int GoInt32;
typedef unsigned int GoUint32;
typedef long long GoInt64;
typedef unsigned long long GoUint64;
typedef GoInt64 GoInt;
typedef GoUint64 GoUint;
typedef __SIZE_TYPE__ GoUintptr;
typedef float GoFloat32;
typedef double GoFloat64;
typedef float _Complex GoComplex64;
typedef double _Complex GoComplex128;

/*
  static assertion to make sure the file is being used on architecture
  at least with matching size of GoInt.
*/
typedef char _check_for_64_bit_pointer_matching_GoInt[sizeof(void*)==64/8 ? 1:-1];

typedef _GoString_ GoString;
typedef void *GoMap;
typedef void *GoChan;
typedef struct { void *t; void *v; } GoInterface;
typedef struct { void *data; GoInt len; GoInt cap; } GoSlice;

#endif

/* End of boilerplate cgo prologue.  */

#ifdef __cplusplus
extern "C" {
#endif


// TODO(lixiaocui): 日志打印看是否需要glog

extern GoUint32 NewEtcdClientV3(struct EtcdConf p0);

extern void EtcdCloseClient();

extern GoUint32 EtcdClientPut(int p0, char* p1, char* p2, int p3, int p4);

/* Return type for EtcdClientGet */
struct EtcdClientGet_return {
    GoUint32 r0;
    char* r1;
    GoInt r2;
};

extern struct EtcdClientGet_return EtcdClientGet(int p0, char* p1, int p2);

/* Return type for EtcdClientList */
struct EtcdClientList_return {
    GoUint32 r0;
    GoUint64 r1;
    GoInt64 r2;
};

// TODO(lixiaocui): list可能需要有长度限制

extern struct EtcdClientList_return EtcdClientList(int p0, char* p1, char* p2, int p3, int p4);

extern GoUint32 EtcdClientDelete(int p0, char* p1, int p2);

extern GoUint32 EtcdClientTxn2(int p0, struct Operation p1, struct Operation p2);

extern GoUint32 EtcdClientCompareAndSwap(int p0, char* p1, char* p2, char* p3, int p4, int p5, int p6);

/* Return type for EtcdClientGetSingleObject */
struct EtcdClientGetSingleObject_return {
    GoUint32 r0;
    char* r1;
    GoInt r2;
};

extern struct EtcdClientGetSingleObject_return EtcdClientGetSingleObject(GoUint64 p0);

/* Return type for EtcdClientGetMultiObject */
struct EtcdClientGetMultiObject_return {
    GoUint32 r0;
    char* r1;
    GoInt r2;
};

extern struct EtcdClientGetMultiObject_return EtcdClientGetMultiObject(GoUint64 p0, GoInt p1);

extern void EtcdClientRemoveObject(GoUint64 p0);

#ifdef __cplusplus
}
#endif