# mcpplibs template Agent Skills

用于指导 Agent 理解 mcpp/mcpplibs 模块库模板、查找外部资料，并在编写或审查 Modern/Module C++ 代码时遵循 mcpp-style-ref 规范。

## 可用技能

| 技能 | 说明 |
|------|------|
| [more-details](more-details/SKILL.md) | mcpp、mcpplibs、包索引、依赖案例、xlings 等资料入口和任务指引 |
| [mcpp-style-ref](mcpp-style-ref/SKILL.md) | 面向 mcpp 项目的 Modern/Module C++ (C++23) 命名、模块化与实践规则 |

## 使用方式

要在 Cursor 中使用，请将技能软链接或复制到项目的 `.cursor/skills/`：

```bash
mkdir -p .cursor/skills
ln -s ../../skills/more-details .cursor/skills/more-details
ln -s ../../skills/mcpp-style-ref .cursor/skills/mcpp-style-ref
```

或安装为个人技能：

```bash
ln -s /path/to/mcpp-template/.agents/skills/more-details ~/.cursor/skills/more-details
ln -s /path/to/mcpp-style-ref/skills/mcpp-style-ref ~/.cursor/skills/mcpp-style-ref
```
