# Plant
这是基于easyx图形库写的《植物大战僵尸》，基本功能实现，僵尸、植物的种类数量、攻击方式有待扩展，声音和显示特效有待改善。
整个代码一千行，代码整洁度有待提高，精简。
项目耗时两天，图片声音素材全部来源于网络。
Plant、Zombie、Grass、Car、Bullet是几个主要的对象，各自负责自身的action和show，Plant、Zombie通过虚函数进行扩展，bullet通过函数对象进行重载。
Plants负责Plant的管理，Zombies负责Zombie的管理，Cars负责Car的管理，Plant负责Bullet的管理和与Zombie的交互。
![程序截图](https://github.com/hjhj111/Plant/blob/master/Plant.png)
