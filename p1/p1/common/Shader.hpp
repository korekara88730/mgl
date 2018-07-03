
#ifndef Shader_hpp
#define Shader_hpp

#include <map>

namespace p1sh {
	GLuint createShaderProgram(const char * vertex_file_path, const char * fragment_file_path);


	enum ShaderType {

		ST_Common,

	};


	class ShaderManager {
	public:
		static ShaderManager* getInstance();
		~ShaderManager();
	
		void initAllShaders();

		GLuint getShaderHandle(ShaderType shaderType) const { return _shaderHash[shaderType]; }
	private:
		ShaderManager();


	private:
		std::map<ShaderType,GLuint> _shaderHash;
	};

};



#endif /* Shader_hpp */
