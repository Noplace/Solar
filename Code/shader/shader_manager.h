/*****************************************************************************************************************
* Copyright (c) 2012 Khalid Ali Al-Kooheji                                                                       *
*                                                                                                                *
* Permission is hereby granted, free of charge, to any person obtaining a copy of this software and              *
* associated documentation files (the "Software"), to deal in the Software without restriction, including        *
* without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell        *
* copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the       *
* following conditions:                                                                                          *
*                                                                                                                *
* The above copyright notice and this permission notice shall be included in all copies or substantial           *
* portions of the Software.                                                                                      *
*                                                                                                                *
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT          *
* LIMITED TO THE WARRANTIES OF MERCHANTABILITY, * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.          *
* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, * DAMAGES OR OTHER LIABILITY,      *
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE            *
* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                                                         *
*****************************************************************************************************************/
#pragma once


#include <unordered_map>

namespace ve {

struct RequestVertexShaderResult {
  int hr;
  ve::VertexShader vs;
  ve::InputLayout il;
};

struct RequestPixelShaderResult {
  int hr;
  ve::PixelShader ps;
};

class ShaderManager : public Component {
 public:
  RequestVertexShaderResult RequestVertexShader(std::string filename, const void* elements, int count);
  RequestPixelShaderResult RequestPixelShader(std::string filename);
  concurrency::task<RequestVertexShaderResult> RequestVertexShaderAsync(std::string filename, const void* elements, int count);
  concurrency::task<RequestPixelShaderResult> RequestPixelShaderAsync(std::string filename);
  void set_resource_path(const std::string& resource_path) { resource_path_ = resource_path; }
 private:
  std::unordered_map<std::string,ve::PixelShader> ps_map;
  std::unordered_map<std::string,ve::VertexShader> vs_map;
  std::unordered_map<std::string,ve::InputLayout> il_map;
  std::string resource_path_;
};

}