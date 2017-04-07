// Copyright 2017 Parikshit Singh

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

//     http://www.apache.org/licenses/LICENSE-2.0

// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


#include <cstdint>
#include <cstdio>
#include <vector>


struct
RGBA
{
  uint8_t r;
  uint8_t g;
  uint8_t b;
  uint8_t a;

  RGBA(uint8_t r ,
       uint8_t g ,
       uint8_t b ,
       uint8_t a = 255);
  RGBA();
};

struct C2DFXEntry
{
  /* Class for a light entry in 2dfx */
  /* Others aren't supported */

  struct header
  {
    float x;
    float y;
    float z;

    uint32_t type = 0;
    uint32_t size = sizeof(data);
  };
  
  struct data
  {
    RGBA color;
    float corona_far_clip;
    float point_light_range;
    float corona_size;
    float shadow_size;
    char corona_show_mode;
    char corona_enable_reflection;
    char corona_flare_type;
    char shadow_color_multiplier;
    char flags1;
    char coronaTexName[24];
    char shadowTexName[24];
    char shadow_z_distance;
    char flags2;
    char padding;
  };

  header entry_header;
  data entry_data;
  
};

class C2DFX
{
  /* Class for reading writing
     .2dfx files */
private:

  std::vector<C2DFXEntry> entries;
  
public:
  
  int write(char* file      );
  int write(const char* file);

  bool addEntry(C2DFXEntry entry);
  
};
