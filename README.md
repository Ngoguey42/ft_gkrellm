# Piscine CPP rush#01 FT_GKRELLM, Apr 2015
>>>>> #####Ncurse+sfml resources monitor. (group project)

#####Grade ``(TBD/125)`` ``(TBD/125)*``
--------  -----------------------

Team: [wide-aze](https://github.com/wide-aze) / [ngoguey](https://github.com/Ngoguey42).

On mac os x:
```sh
make sfml all
DYLD_FRAMEWORK_PATH=`pwd`"/SFML/Frameworks" ./ft_gkrellm
```

### Classes tree:
```cpp

namespace ft;
class IMonitorDisplay;
class IMonitorModule;
class TimeModule : public IMonitorModule;
CPUModule.hpp:class CPUModule : public IMonitorModule;
DiskModule.hpp:class DiskModule : public IMonitorModule;
HostnameModule.hpp:class HostnameModule : public IMonitorModule;
NetworkModule.hpp:class NetworkModule : public IMonitorModule;
OSinfoModule.hpp:class OSinfoModule : public IMonitorModule;
RAMModule.hpp:class RAMModule : public IMonitorModule;

namespace ftsf; //ft_sfml
class Window : public ft::IMonitorDisplay, public sf::RenderWindow; //singleton
class Background : public sf::Drawable; //singleton, one inside the above Window class
class Module : public sf::Drawable; //one for each ft::IMonitorModule
class RoundedBox : public sf::Drawable; //contains 4xsf::CircleShape and 1xsf::ConvexShape
class DefaultTextBox : public RoundedBox; //contains 1xsf::Text

namespace ftnc; //ft_ncurses
class Window : public ft::IMonitorDisplay; //singleton
class Line : public std::string; //one for each line in the terminal
```

<br>
 
<br><br><br><br><br><br><br><br>
