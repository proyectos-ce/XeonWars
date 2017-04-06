//
// Created by joseph on 3/25/17.
//

#include "Utils.h"

const sf::Vector2u Utils::designedsize(1366,768);

sf::View Utils::calcView(const sf::Vector2u &windowsize, const sf::Vector2u &designedsize)
{
    sf::FloatRect viewport(0.f, 0.f, 1.f, 1.f);

    float screenwidth = windowsize.x / static_cast<float>(designedsize.x);
    float screenheight = windowsize.y / static_cast<float>(designedsize.y);

    if(screenwidth > screenheight)
    {
        viewport.width = screenheight / screenwidth;
        viewport.left = (1.f - viewport.width) / 2.f;
    }
    else if(screenwidth < screenheight)
    {
        viewport.height = screenwidth / screenheight;
        viewport.top = (1.f - viewport.height) / 2.f;
    }

    sf::View view( sf::FloatRect( 0, 0, designedsize.x , designedsize.y ) );
    view.setViewport(viewport);

    return view;
}
