/*
 * =====================================================================================
 *
 *       Filename:  LibDevKMApi.h
 *
 *    Description:  Static library interface of DeviceRootKeyService.
 *
 *        Version:  1.0
 *        Created:  06/28/2017 11:12:36 PM
 *       Compiler:  armcc
 *
 *         Author:  Dongwook Shim (), dw.shim@samsung.com
 *        Company:  Samsung Electronics
 *
 *        Copyright (c) 2017 by Samsung Electronics, All rights reserved. 
 *
 * =====================================================================================
 */

#ifndef __LIBDEVKM_API_H__
#define __LIBDEVKM_API_H__

#include <stddef.h>
#include <stdint.h>

/*******************************************
 * 
 * Error codes.
 *
 *******************************************/

#define ERR_BASE                           (int32_t)  -10000
#define NO_ERROR                           0
#define ERR_UNSUPPORTED_CMD                ERR_BASE + (int32_t) -1
#define ERR_INVALID_ARGUMENT               ERR_BASE + (int32_t) -2
#define ERR_BUFFER_OVERFLOW                ERR_BASE + (int32_t) -3
#define ERR_NOT_ENOUGH_MEMORY              ERR_BASE + (int32_t) -4
#define ERR_PERMISSION_DENIED              ERR_BASE + (int32_t) -5
#define ERR_NOT_IMPLEMENTED                ERR_BASE + (int32_t) -6
#define ERR_FILE_READ_FAILED               ERR_BASE + (int32_t) -7
#define ERR_FILE_WRITE_FAILED              ERR_BASE + (int32_t) -8
#define ERR_INVALID_BLOB                   ERR_BASE + (int32_t) -9
#define ERR_DRK_IS_NOT_EXIST               ERR_BASE + (int32_t) -10
#define ERR_WRONG_ORDER                    ERR_BASE + (int32_t) -11
#define ERR_BASE64_CODING_FAILED           ERR_BASE + (int32_t) -12
#define ERR_HASH_VERIFICATION_FAILED       ERR_BASE + (int32_t) -13

#define ERR_WB_API_OPERATION_FAILED        ERR_BASE + (int32_t) -100
#define ERR_SYSCALL_FAILED                 ERR_BASE + (int32_t) -101
#define ERR_PLATFORM_API_OPERATION_FAILED  ERR_BASE + (int32_t) -102
#define ERR_DRIVER_API_OPERATION_FAILED    ERR_BASE + (int32_t) -103
#define ERR_TA_LOADING_FAILED              ERR_BASE + (int32_t) -104

#define ERR_RILD_BASE                      ERR_BASE + (int32_t) -1000
#define ERR_WAIT_CONDITION_ERROR           ERR_RILD_BASE + ( int32_t ) -1
#define ERR_RILD_CONNECT_ERROR             ERR_RILD_BASE + ( int32_t ) -2
#define ERR_RILD_REQUEST_HOOK_ERROR        ERR_RILD_BASE + ( int32_t ) -3
#define ERR_RILD_SET_HANDLER_ERROR         ERR_RILD_BASE + ( int32_t ) -83

#define ERR_TA_BASE                        ERR_BASE + (int32_t) -2000
#define ERR_TA_UNSUPPORTED_CMD             ERR_TA_BASE + (int32_t) -1
#define ERR_TA_INVALID_ARGUMENT            ERR_TA_BASE + (int32_t) -2
#define ERR_TA_BUFFER_OVERFLOW             ERR_TA_BASE + (int32_t) -3
#define ERR_TA_NOT_ENOUGH_MEMORY           ERR_TA_BASE + (int32_t) -4
#define ERR_TA_PARSING_FAILED              ERR_TA_BASE + (int32_t) -5
#define ERR_TA_KEYPAIR_MISMATCHED          ERR_TA_BASE + (int32_t) -6
#define ERR_TA_VERIFICATION_FAILED         ERR_TA_BASE + (int32_t) -7
#define ERR_TA_INVALID_BLOB                ERR_TA_BASE + (int32_t) -8
#define ERR_TA_NOT_SECURE                  ERR_TA_BASE + (int32_t) -9
#define ERR_TA_REVOCATED_CERT              ERR_TA_BASE + (int32_t) -10
#define ERR_TA_GEN_RANDOM_FAILED           ERR_TA_BASE + (int32_t) -11
#define ERR_TA_GEN_HASH_FAILED             ERR_TA_BASE + (int32_t) -12
#define ERR_TA_CRYPTO_API_ERROR            ERR_TA_BASE + (int32_t) -13
#define ERR_TA_PERMISSION_DENIED           ERR_TA_BASE + (int32_t) -14
#define ERR_TA_INVALID_KEY_LENGTH          ERR_TA_BASE + (int32_t) -15
// 101 ~ 409 are reserved by TlApiError.h

#define ERR_TA_SWB_BASE                    ERR_BASE + (int32_t) -3000
#define ERR_TA_SWB_FAILURE                 ERR_TA_SWB_BASE + (int32_t) -1
#define ERR_TA_SWB_PARAM_CTX_NULL          ERR_TA_SWB_BASE + (int32_t) -2
#define ERR_TA_SWB_PARAM_KEY_NULL          ERR_TA_SWB_BASE + (int32_t) -3
#define ERR_TA_SWB_PARAM_IV_NULL           ERR_TA_SWB_BASE + (int32_t) -4
#define ERR_TA_SWB_PARAM_OUT_NULL          ERR_TA_SWB_BASE + (int32_t) -5
#define ERR_TA_SWB_PARAM_IN_NULL           ERR_TA_SWB_BASE + (int32_t) -6
#define ERR_TA_SWB_PARAM_IN_LENGTH_INVALID ERR_TA_SWB_BASE + (int32_t) -7
#define ERR_TA_SWB_PARAM_OUT_LENGTH_NULL   ERR_TA_SWB_BASE + (int32_t) -8
#define ERR_TA_SWB_FILE_OPEN_FAILED        ERR_TA_SWB_BASE + (int32_t) -9
#define ERR_TA_SWB_FILE_READ_FAILED        ERR_TA_SWB_BASE + (int32_t) -10
#define ERR_TA_SWB_RESOURCE_UNLOADED       ERR_TA_SWB_BASE + (int32_t) -11
#define ERR_TA_SWB_CIPHER_MODE_INVALID     ERR_TA_SWB_BASE + (int32_t) -12
#define ERR_TA_SWB_OUTPUT_SIZE_INVALID     ERR_TA_SWB_BASE + (int32_t) -20

#define ERR_SRKWB_BASE                     ERR_BASE + (int32_t) -3500
// -1 ~ -6 are reserved by waes_client_api.h

#define ERR_TA_SRKWB_BASE                  ERR_BASE + (int32_t) -3510
// -1 ~ -6 are reserved by waes_client_api.h

#define ERR_TA_X509_PARSE_BASE             ERR_BASE + (int32_t) -4000
// -1 ~ -15 are reserved by x509_parser_error_t at x509v3.h.

#define ERR_TA_QSEE_BASE                   ERR_BASE + (int32_t) -10000
#define ERR_TA_BF_BASE                     ERR_TA_QSEE_BASE
// -73 ~ -95 are reserved by qsee_message.h


#define MAX_SERVICE_NAME            8
#define MAX_SERIALNO_SIZE           32
#define MAX_MODEL_SIZE              32

#ifdef __cplusplus
extern "C" {
#endif

typedef enum 
{
	KEY_TYPE_NONE = 0,
	KEY_TYPE_RSA  = 0x01,
	RSA_KEY = 0x01,
	KEY_TYPE_EC   = 0x04,
	KEY_TYPE_MAX
}KeyType_t;

struct KeyInfo
{
    /* 52 is for backward compatibility
     * size of KeyInfo must be equal to the old value */
    uint8_t serviceName[52];
    /* device serial number */
    uint8_t serialno[MAX_SERIALNO_SIZE];
    /* model name, ex: SGH-I337 */
    uint8_t model[MAX_MODEL_SIZE];
    /* date */
    uint16_t year;
    uint8_t mon;
    uint8_t mday;
    uint8_t hour;
    uint8_t min;
    uint8_t sec;
    /* key length in bits, default 2048 */
    uint32_t keyLen;
    /* 1 - crt rsa, 0 - without crt */
    uint32_t crt;
};

typedef struct
{
	uint8_t keyType;
	char serviceName[MAX_SERVICE_NAME + 1];
	char model[MAX_MODEL_SIZE];
	char serialNo[MAX_SERIALNO_SIZE];
	uint32_t keyLength;
} __attribute__((packed)) ServiceKeyInfo_t;

/**
 * Function : createServiceKeySession()
 * Description : Create service key session and get service key.
 * 	             Should load your trustzone application before calling this function on QSEE.
 * 	             And should call releaseServiceKeySession() on QSEE.
 * 	             Only Dm-verity can get service key.
 * Parameters : @ serviceKeyInfo : service key infomation you request.
 *                    keyType and serviceName should be filled. Other parameters are generated automatically.
 *              @ outData : Wrapped key blob.
 *              @ outDataLen : Wrapped key blob length.
 *              @ tlv : X.509 extension field. Generally set as NULL.
 *              @ tlvLen : X.509 extension field's length. Generally set as 0.
 * Return value : Return 0 if it was successful. Or return negative value.
 */
int createServiceKeySession(ServiceKeyInfo_t *serviceKeyInfo, uint8_t *outData, size_t *outDataLen, uint8_t *tlv, size_t tlvLen);

/**
 * Function : verifyDeviceRootKey()
 * Description : Check device root key is exist.
 * Parameters : @ keyType : Currently only KEY_TYPE_RSA is supported.
 * Return value : Return 0 if device root key was exist. Or return negative value.
 */
int verifyDeviceRootKey(KeyType_t keyType);

#if (defined USE_QSEE)
/**
 * Function : releaseServiceKeySession()
 * Description : Device root key trust application should be loaded to share wrapped key blob on QSEE.
 *               Should call after completinig parsing key.
 *               DRK service will be bloocked if you don't call this function on QSEE.
 * Parameters : None.
 * Return value : None.
 */
void releaseServiceKeySession(void);
#endif	// End of USE_QSEE

/**************************************************************************************
 *
 * Deprecated functions - DO NOT USE BELOW FUNCTIONS.
 *
 **************************************************************************************/

/**
 * Function : generateServiceKey()
 * Description : Create service key session and get service key for Tbase or Teegris.
 * 	             Only Dm-verity can get service key and file is generated at /efs/prov_data/dmvt/dmvt.dat.
 *               Do nothing and return 0 on QSEE.
 * Parameters : @ keyType : KEY_TYPE_RSA or KEY_TYPE_EC. 
 *              @ keyInfo : This parameter doesn't be used any more. Just set as NULL.
 *              @ keyInfoLen : This parameter doesn't be used any more. Just set as 0.
 *              @ TID : Only Dm-verity's TID is valid.
 *              @ TIDLen : This parameter doesn't be used any more. Just set as 0.
 * Return value : Return 0 if device root key was exist. Or return negative value.
 */
int generateServiceKey(uint8_t keyType, const uint8_t* keyInfo, uint32_t keyInfoLen, const void *TID, uint32_t TIDLen);

#if (defined USE_QSEE)
/**
 * Function : shareServiceKeyInit()
 * Description : Do nothing. Always return 0.
 *               This function is only for preventing build error.
 * Parameters : None. 
 * Return value : Always return 0.
 */
int shareServiceKeyInit(void);

/**
 * Function : shareServiceKey()
 * Description : Create service key session and get service key on QSEE..
 * 	             Should call shareServiceKeyFinal() or releaseServiceKeySession().
 * Parameters : @ serviceName : Only Dm-verity's name is valid.
 *              @ outData : Wrapped key blob.
 *              @ outDataLen : Wrapped key blob length.
 * Return value : Return 0 if device root key was exist. Or return negative value.
 */
int shareServiceKey(const char* serviceName, uint8_t *outData, uint32_t *outDataLen);

/**
 * Function : releaseServiceKeySession()
 * Description : Device root key trust application should be loaded to share wrapped key blob on QSEE.
 *               Should call after completinig parsing key.
 *               DRK service will be bloocked if you don't call this function on QSEE.
 * Parameters : None.
 * Return value : Always return 0.
 */
int shareServiceKeyFinal(void);
#endif	// End of USE_QSEE
#ifdef __cplusplus
}
#endif
#endif	// End of __LIBDEVKM_API_H__
