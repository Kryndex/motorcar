/****************************************************************************
**This file is part of the Motorcar 3D windowing framework
**
**
**Copyright (C) 2015 Forrest Reiling
**
**
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
**
****************************************************************************/

#ifndef OCULUSHMD_H
#define OCULUSHMD_H

#include <scenegraph/output/display/rendertotexturedisplay.h>
#include <scenegraph/input/singlebonetracker.h>

#include <OVR_Version.h>
#include <OVR_CAPI.h>
#include <OVR_CAPI_GL.h>


#include <glm/gtc/quaternion.hpp>

namespace motorcar {

class OculusHMD : public RenderToTextureDisplay
{
public:
    
    bool isInitialized(){ return m_initialized;}

    virtual void prepareForDraw() override;
    virtual void finishDraw() override;

    static void initializeLibOVR();
    OculusHMD(Skeleton *skeleton, OpenGLContext *glContext, PhysicalNode *parent);
    ~OculusHMD();

private:

    bool m_initialized;
    ovrHmd m_hmd;
    ovrVector3f m_hmdToEyeViewOffset[2];


    unsigned int m_frameIndex;

};
}


#endif // OCULUSHMD_H
