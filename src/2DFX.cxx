#include <2DFX.hh>


// RGBA Class 
// ----------------------


RGBA::RGBA(uint8_t r ,
	   uint8_t g ,
	   uint8_t b ,
	   uint8_t a)
{
  /* Constructor */
  this->r = r;
  this->g = g;
  this->b = b;
  this->a = a;
}

RGBA::RGBA()
{
  this->r = 255;
  this->g = 255;
  this->b = 255;
  this->a = 255;
}

bool C2DFX::addEntry(C2DFXEntry entry)
{
  this->entries.push_back(entry);
}

int C2DFX::write(char* file)
{
  this->write((const char*) file);
}

int C2DFX::write(const char* file)
{
  FILE* output = fopen(file,"w");
  
  //thats the header.
  uint32_t header_entry_count = this->entries.size();
  fwrite(&header_entry_count,
	 4,
	 1,
	 output);

  for(int i = 0;
      i < this->entries.size();
      ++i)
    {
      fwrite(&this->entries[i].entry_header,
	     sizeof(C2DFXEntry::header),
	     1,
	     output);
      
      fwrite(&this->entries[i].entry_data,
	     sizeof(C2DFXEntry::data),
	     1,
	     output);
    }
  
}

