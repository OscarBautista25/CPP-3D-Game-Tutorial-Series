/*MIT License

CX3D Game Framework (https://github.com/PardCode/CX3D)

Copyright (c) 2019-2024, PardCode

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.*/

#pragma once

#include <CX3D/CXPrerequisites.h>
#include <CX3D/Resource/CXResource.h>
#include <vector>



class  CXGraphicsEngine;
class  CXMaterial : public  CXResource
{
public:
	CXMaterial(const wchar_t* full_path, CXResourceManager* manager);
	CXMaterial(const  CXMaterialPtr& material, CXResourceManager* manager);

	void addTexture(const  CXTexturePtr& texture);
	void removeTexture(unsigned int index);

	void setData(void* data, unsigned int size);
	void setUserData(void* data, unsigned int size);

	void setCullMode(const  CXCullMode& mode);
	CXCullMode getCullMode();
private:
	CXShaderPtr m_shader;
	CXConstantBufferPtr m_constant_buffer;
	CXConstantBufferPtr m_userBuffer;
	std::vector<CXTexturePtr> m_vec_textures;
	CXCullMode m_cull_mode = CXCullMode::Back;
	friend class  CXGraphicsEngine;
};

