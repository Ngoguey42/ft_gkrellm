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

namespace ft:
class IMonitorDisplay
class IMonitorModule
class TimeModule : public IMonitorModule

namespace ftsf:
class Background : public sf::Drawable
class DefaultTextBox : public RoundedBox
class Module : public sf::Drawable
class RoundedBox : public sf::Drawable
class Window : public sf::RenderWindow, public ft::IMonitorDisplay

```

<br>
 
<br><br><br><br><br><br><br><br>
