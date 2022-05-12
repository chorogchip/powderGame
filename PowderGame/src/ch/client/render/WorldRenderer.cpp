#include "WorldRenderer.h"
#include "../../main/Game.h"

namespace ch {

WorldRenderer::WorldRenderer() { }
WorldRenderer::~WorldRenderer() { }

void WorldRenderer::render(World& world) {

  //init
  float map_front_x_, map_front_y_, map_end_x_, map_end_y_;
  int map_front_x, map_front_y, map_end_x, map_end_y;
  auto& my_render_states = Game::getInstance()->getRenderstate();
  
  // calculate pixel size to render
  const auto winsize = Game::getInstance()->getWindow().getSize();
  map_front_x_ = static_cast<int>(my_render_states.cam_pos.x - static_cast<float>(winsize.x >> 1) / my_render_states.cam_zoom);
  map_front_y_ = static_cast<int>(my_render_states.cam_pos.y - static_cast<float>(winsize.y >> 1) / my_render_states.cam_zoom);
  map_end_x_ = map_front_x_ + static_cast<float>(winsize.x) / my_render_states.cam_zoom;
  map_end_y_ = map_front_y_ + static_cast<float>(winsize.y) / my_render_states.cam_zoom;

  //temp code that makes rendered tile size little less than window to test
#if 0
  map_front_x += 10;
  map_front_y += 10;
  map_end_x -= 10;
  map_end_y -= 10;
#endif

  // limit pixel size to render
  map_front_x = std::max(0, static_cast<int>(map_front_x_));
  map_front_y = std::max(0, static_cast<int>(map_front_y_));
  map_end_x = std::min(world.map_x_, static_cast<int>(map_end_x_));
  map_end_y = std::min(world.map_y_, static_cast<int>(map_end_y_));
  if(map_front_x > map_end_x) {
    map_end_x = map_front_x;
  }
  if(map_front_y > map_end_y) {
    map_end_y = map_front_y;
  }

  // map size
  const float map_x_ = map_end_x_ - map_front_x_;
  const float map_y_ = map_end_y_ - map_front_y_;
  const int map_x = map_end_x - map_front_x;
  const int map_y = map_end_y - map_front_y;


  //translate
  sf::RenderStates sf_render_states;
  sf_render_states.transform
    .translate(sf::Vector2f(static_cast<float>(winsize.x >> 1), static_cast<float>(winsize.y >> 1)))
    .scale(sf::Vector2f(my_render_states.cam_zoom, my_render_states.cam_zoom))
    .translate(sf::Vector2f(-map_x_ / 2.0f, -map_y_ / 2.0f))
    .translate(sf::Vector2f(static_cast<float>(map_front_x) - map_front_x_,
                            static_cast<float>(map_front_y) - map_front_y_))
    ;

  // make vertexarray
  sf::VertexArray vertex_arr = sf::VertexArray(sf::Quads, (map_x * map_y) << 2);
  
  // set values
  int inv2;
  float xx, yy;
  for(int i = 0; i != map_y; ++i) {
    for(int j = 0; j != map_x; ++j) {
      inv2 = (i * map_x + j) << 2;
      xx = static_cast<float>(j);
      yy = static_cast<float>(i);
      vertex_arr[inv2    ].position = sf::Vector2f(xx,        yy        );
      vertex_arr[inv2 + 1].position = sf::Vector2f(xx + 1.0f, yy        );
      vertex_arr[inv2 + 2].position = sf::Vector2f(xx + 1.0f, yy + 1.0f);
      vertex_arr[inv2 + 3].position = sf::Vector2f(xx,        yy + 1.0f);

      auto color = world.map_[(map_front_y + i) * world.map_x_ + (map_front_x + j)].getTileColor();
      vertex_arr[inv2    ].color = color;
      vertex_arr[inv2 + 1].color = color;
      vertex_arr[inv2 + 2].color = color;
      vertex_arr[inv2 + 3].color = color;
    }
  }

  //render
  Game::getInstance()->getWindow().draw(vertex_arr, sf_render_states);
}


}