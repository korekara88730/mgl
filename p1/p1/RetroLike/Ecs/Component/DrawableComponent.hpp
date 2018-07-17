#include "BaseComponent.hpp"
#include "../../Drawable/Drawable.hpp"

class DrawableComponent : public BaseComponent {
public:
	DrawableComponent();
	virtual ~DrawableComponent();

	void init(Drawable* pDrawable);

	void update(float deltaTime);
	void draw(glm::mat4& modelMatrix, glm::mat4& viewMatrix, glm::mat4 projectionMatrix);
private:
	Drawable*	_pDrawable = nullptr;
};

