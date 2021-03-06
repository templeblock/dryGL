//
//  Ibo.h
//  dryGL
//
//  Created by Jordi Ros on 15/02/13.
//  Copyright (c) 2013 Jordi Ros. All rights reserved.
//

#ifndef DRY_GRAPHICS_IBO_H_
#define DRY_GRAPHICS_IBO_H_

namespace dry {

class Ibo
{
public:
                Ibo         () { m_Ibo = 0; }
               ~Ibo         () { Free(); }
    
    bool        Init        (void const *data, int size, DataType type, bool dynamic);
    void        Free        ();

    void        Update      (void const *data, int size, int offset);

    void        Bind        ();
    void        Unbind      ();
    
    int         GetType     () { return m_Type; }
    int         GetSize     () { return m_Size; }

private:
    
    int         m_Ibo;
    int         m_Size;
    DataType    m_Type;
    int         m_TypeSize;
    int         m_GLVar;
    bool        m_Dynamic;
};

}

#endif
