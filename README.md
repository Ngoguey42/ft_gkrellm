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

namespace ftsf;
class Window : public sf::RenderWindow, public ft::IMonitorDisplay; //singleton
class Background : public sf::Drawable; //singleton, one inside the above Window class
class Module : public sf::Drawable; //one for each ft::IMonitorModule
class RoundedBox : public sf::Drawable; //contains 4xsf::CircleShape and 1xsf::ConvexShape
class DefaultTextBox : public RoundedBox; //contains 1xsf::Text
```

<br>
 
<br><br><br><br><br><br><br><br>
