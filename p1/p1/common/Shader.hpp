
#ifndef Shader_hpp
#define Shader_hpp

#include <map>

namespace p1sh {
	GLuint createShaderProgram(const char * vertex_file_path, const char * fragment_file_path);


	enum ShaderType {
		ST_Base,
		ST_MVP,
		ST_Common,
	};


	class ShaderManager {
	public:
		static ShaderManager* getInstance();
		~ShaderManager();
	
		void initAllShaders();

		GLuint ShaderManager::getShaderHandle(ShaderType shaderType) const {
			auto iter = _shaderHash.find(shaderType);
			if (iter == _shaderHash.end()) {
				return (GLuint)0;
			}
			return iter->second;
		}

	private:
		ShaderManager();


	private:
		std::map<ShaderType,GLuint> _shaderHash;
	};

};



#endif /* Shader_hpp */
