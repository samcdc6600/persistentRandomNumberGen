#include <random>
#include <sstream>
#include <fstream>

int getIntFromFile(const int rDefault, const std::string f);

void saveIntToFile(const std::string f, const int a);

int main(void)
{
  constexpr int DEFAULT_NUM_FILES {2};
  const int numFiles {getIntFromFile(DEFAULT_NUM_FILES, "/usr/home/cyan/.config/sleep/images/numImages")};
  std::mt19937 rng;//a Mersenne Twister pseudo-random generator of 32-bit numbers with a state size of 19937 bits.
  rng.seed(std::random_device()());
  std::uniform_int_distribution<std::mt19937::result_type> dist (1, numFiles); // distribution in range [1, numFiles]

  saveIntToFile("/usr/home/cyan/.config/sleep/images/nextImage", dist(rng));  

  return 0;
}

int getIntFromFile(const int rDefault, const std::string f)
{
    int ret {};
    std::ifstream in(f.c_str());
    if(in.is_open())
      {
	in>>ret;
	in.close();
      }
    else
      ret = rDefault;
    return ret;
}

void saveIntToFile(const std::string f, const int a)
{
  std::ofstream out(f.c_str());      
  out<<a<<"\0";
  out.close();
}
