#include "WorldRenderer.h"
#include "../../main/Game.h"

namespace ch {

WorldRenderer::WorldRenderer() { }
WorldRenderer::~WorldRenderer() { }

void WorldRenderer::render(World& world) {
  auto& my_render_states = Game::getInstance()->getRenderstate();
  int map_front_x, map_front_y, map_end_x, map_end_y;
  sf::RenderStates render_states;
  render_states.transform.translate(my_render_states.cam_pos)
                         .scale(sf::Vector2f(my_render_states.cam_zoom, my_render_states.cam_zoom));
  
  // calculate pixel size to render


  // make vertexarray
  const int map_x = map_end_x - map_front_x;
  const int map_y = map_end_y - map_front_y;
  sf::VertexArray vertex_arr = sf::VertexArray(sf::Quads, (map_x * map_y) << 2);

  // set values
  //TODO
  int inv1, inv2;
  for(int i = 0; i != (map_x * map_y); i += map_y) {
    for(int j = 0; j != map_y; ++j) {
      inv1 = (i + j) << 2;
      inv2 = (i + j);
      vertex_arr[inv2].position;

      vertex_arr[inv2].color = world.map_[inv2];
      vertex_arr[inv2].color;
      vertex_arr[inv2].color;
      vertex_arr[inv2].color;

    }
  }

  //render
  Game::getInstance()->getWindow().draw(vertex_arr, render_states);

}


}