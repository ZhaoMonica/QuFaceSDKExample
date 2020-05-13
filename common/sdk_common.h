/**
 * @file sdk_common.h
 * @brief
 *
 */

#ifndef __SDK_COMMON__H__
#define __SDK_COMMON__H__

#include "sz_common.h"
#include "sz_face_module.h"

#define MAX_FILE_LEN 256
#ifdef __cplusplus
extern "C" {
#endif

SZ_RETCODE init_handles(const char *modelFile, SZ_FACE_CTX **pFaceCtx,
                        SZ_LICENSE_CTX **pLicenseCtx, SZ_NET_CTX **pNetCtx);

unsigned char *loadModel(const char *modelFile, int *pModelLen);
unsigned char *jpg2Bgr(const char *jpgFile, int *pWidth, int *pHeight);
unsigned char *readImage(const char *jpgFile, int *pWidth, int *pHeight);
unsigned char *jpg2Nv21(const char *jpgFile, int *pWidth, int *pHeight);
SZ_BOOL getImageFromjpg(const char *jpgFile, SZ_IMAGE_CTX **pImgCtx);

SZ_BOOL getFeature(const char *jpgFile, SZ_FACE_CTX *faceCtx,
                   SZ_IMAGE_CTX *imageCtx, SZ_FACE_FEATURE **pFeature,
                   SZ_INT32 *pFeatureLen);

void saveDetection2File(const char *jpgFile, const char *pData, int w, int h,
                        int scaleN, int faceCnt, SZ_FACE_CTX *faceCtx);

#ifdef __cplusplus
}
#endif

#endif
