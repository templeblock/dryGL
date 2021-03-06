//
//  QuadBatch.h
//  dryGL
//
//  Created by Jordi Ros on 15/02/13.
//  Copyright (c) 2013 Jordi Ros. All rights reserved.
//

#ifndef DRY_ADDONS_QUADBATCH_H_
#define DRY_ADDONS_QUADBATCH_H_

namespace dry {

class QuadBatch
{
public:
                    QuadBatch       () { }
                   ~QuadBatch       () { Free(); }
    
    void            Init            (Renderer *renderer);
    void            Free            ();
    
    void            DrawTexture     (Texture *texture, Camera const *camera, glm::mat4 const &transform, float x, float y, float w, float h);
    void            DrawShader      (Shader  *shader,  Camera const *camera, glm::mat4 const &transform, float x, float y, float w, float h);

private:
    

private:

    Renderer       *m_Renderer;
    Vbo             m_Vertices;
    Vbo             m_TexCoords;
    Ibo             m_Indices;
    Shader          m_Shader;
};

}

#endif
