#include <jni.h>
#include <string>

#include "gl/glrenderer.h"
#include "common/application_base.h"
#include "AndroidHelper.h"

extern "C"
JNIEXPORT jstring

JNICALL
Java_gles_opengl_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

static Renderer *renderer = nullptr;

extern "C"
JNIEXPORT void JNICALL
Java_gles_opengl_MyRenderer_nativeSurfaceCreate(
        JNIEnv *env,
        jclass type,
        jobject assetManager) {

    AndroidHelper::setEnvAndAssetManager(env, assetManager);
    renderer = new GLRenderer();
    ApplicationBase::RegisterApplications(renderer);
    ApplicationBase::ActiveApplication()->Init();


}

extern "C"
JNIEXPORT void JNICALL
Java_gles_opengl_MyRenderer_nativeSurfaceChange(
        JNIEnv *env,
        jclass type,
        jint width,
        jint height) {

}

extern "C"
JNIEXPORT void JNICALL
Java_gles_opengl_MyRenderer_nativeDrawFrame(
        JNIEnv *env,
        jclass type) {

    ApplicationBase::ActiveApplication()->Update();
    ApplicationBase::ActiveApplication()->Render();


}
