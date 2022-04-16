#include "WorldRenderer.h"
#include "../../main/Game.h"

namespace ch {

WorldRenderer::WorldRenderer() { }
WorldRenderer::~WorldRenderer() { }

void WorldRenderer::render(World& world) {

  //init
  int map_front_x, map_front_y, map_end_x, map_end_y;
  auto& my_render_states = Game::getInstance()->getRenderstate();
  
  // calculate pixel size to render
  const auto winsize = Game::getInstance()->getWindow().getSize();
  map_front_x = static_cast<int>(my_render_states.cam_pos.x);
  map_front_y = static_cast<int>(my_render_states.cam_pos.y);
  map_end_x = map_front_x + static_cast<int>(static_cast<float>(winsize.x) / my_render_states.cam_zoom);
  map_end_y = map_front_y + static_cast<int>(static_cast<float>(winsize.y) / my_render_states.cam_zoom);

  // limit pixel size to render
  map_front_x = std::max(0, map_front_x);
  map_front_y = std::max(0, map_front_y);
  map_end_x = std::min(world.map_x_, map_end_x);
  map_end_y = std::min(world.map_y_, map_end_y);
  if(map_front_x > map_end_x) {
    map_end_x = map_front_x;
  }
  if(map_front_y > map_end_y) {
    map_end_y = map_front_y;
  }

  //translate
  sf::RenderStates sf_render_states;
  sf_render_states.transform
    .scale(sf::Vector2f(my_render_states.cam_zoom, my_render_states.cam_zoom))
    .translate(my_render_states.cam_pos + sf::Vector2f(map_front_x, map_front_y))
    ;
  
  // map size
  const int map_x = map_end_x - map_front_x;
  const int map_y = map_end_y - map_front_y;
  const int map_x_2 = (map_x << 1) + 3;

  // make vertexarray
  sf::VertexArray vertex_arr = sf::VertexArray(sf::TriangleStrip, map_x_2 * map_y);
  
  // set values
  for(int i = 0; i != map_y; ++i) {
    const int add_yindx = i * map_x_2;

    vertex_arr[add_yindx].position = sf::Vector2f(0.0f, static_cast<float>(i));
    vertex_arr[add_yindx + 1].position = sf::Vector2f(0.0f, static_cast<float>(i + 1));

    vertex_arr[add_yindx].color = world.map_[i * map_x].getTileColor();
    vertex_arr[add_yindx + 1].color = world.map_[i * map_x].getTileColor();

    for(int j = 1; j <= map_x; ++j) {
      const int jj = j << 1;

      vertex_arr[add_yindx + jj].position = sf::Vector2f(static_cast<float>(j), static_cast<float>(i));
      vertex_arr[add_yindx + jj + 1].position = sf::Vector2f(static_cast<float>(j), static_cast<float>(i + 1));

      vertex_arr[add_yindx + jj].color = world.map_[i * map_x + j - 1].getTileColor();
      vertex_arr[add_yindx + jj + 1].color = world.map_[i * map_x + j - 1].getTileColor();
    }

    vertex_arr[add_yindx + map_x_2 - 1].position = sf::Vector2f(static_cast<float>(map_x), static_cast<float>(i + 1));

    vertex_arr[add_yindx + map_x_2 - 1].color = sf::Color::White;

  }

  //render
  Game::getInstance()->getWindow().draw(vertex_arr, sf_render_states);
}


}