# mcpplibs.mylib

> 一个最小 mcpp C++23 模块库示例：`import mcpplibs.mylib;`

[![C++23](https://img.shields.io/badge/C%2B%2B-23-blue.svg)](https://en.cppreference.com/w/cpp/23)
[![Module](https://img.shields.io/badge/module-ok-green.svg)](https://en.cppreference.com/w/cpp/language/modules)
[![License](https://img.shields.io/badge/license-Apache_2.0-blue.svg)](LICENSE)

一个基于 mcpp 构建工具的**现代C++模块化库**模板仓库

## Quick Start / 快速开始

1. 打开模板仓库：https://github.com/mcpplibs/template
2. 点击 [**Use this template**](https://github.com/new?template_name=template&template_owner=mcpplibs) 创建自己的库仓库。
3. 克隆新仓库到本地：

```bash
git clone https://github.com/<your-org>/<your-lib>.git
cd <your-lib>
```

4. 先运行默认模板，确认环境可用：

<details>
<summary>点击查看xlings安装命令</summary>

**Linux / macOS**
```bash
curl -fsSL https://d2learn.org/xlings-install.sh | bash
```

**Windows — PowerShell**
```powershell
irm https://d2learn.org/xlings-install.ps1.txt | iex
```

> xlings 详情 → [xlings.d2learn.org](https://xlings.d2learn.org)

</details>

```bash
xlings install
mcpp build
mcpp test
```

5. 再把 `mylib` 替换成你的库名，重点修改：

- `mcpp.toml` 的包名、描述和仓库地址
- `src/mylib.cppm` 的模块名和 API
- `tests/mylib_test.cpp` 的测试用例
- `examples/basic/` 的依赖和 import
- README 与 `docs/architecture.md` 中的说明

## Library Example

当前库导出一个简单 API：

```cpp
import std;
import mcpplibs.mylib;

int main() {
    std::println("{}", mcpplibs::mylib::hello_mcpplibs());
}
```

输出：

```text
hello mcpplibs
```

相关文件：

- `src/mylib.cppm`: 模块接口
- `tests/mylib_test.cpp`: 单元测试
- `examples/basic/`: 使用方示例

运行使用方示例：

```bash
cd examples/basic
mcpp run
```

需要添加依赖时，在 `mcpp.toml` 中声明：

```toml
[dependencies.mcpplibs]
cmdline = "0.0.2"
```

然后在需要的位置直接 `import mcpplibs.cmdline;`。不要默认在主模块里 `export import` 第三方依赖，除非公开 API 确实要暴露依赖包类型。

## 其他项目如何使用编写的库

开发期或同项目内可以直接用本地路径：

```toml
[dependencies]
mylib = { path = "../mylib" }
```

还没有进入包索引时，可以引用 Git 仓库：

```toml
[dependencies]
mylib = { git = "https://github.com/mcpplibs/mylib.git", tag = "v0.1.0" }
```

发布到 mcpp 包索引后，可以只按名字和版本引用：

```toml
[dependencies]
mylib = "0.1.0"
```

代码里统一直接导入模块：

```cpp
import mcpplibs.mylib;
```

## AI Agent 辅助了解和开发

可以让 AI Agent 辅助你了解这个仓库及开发，可以先添加下面提示词：

```text
仓库地址：https://github.com/mcpplibs/template

先阅读 .agents/skills/more-details/SKILL.md、.agents/skills/mcpp-style-ref/SKILL.md 和 docs/architecture.md。

先只了解这个模板的 mcpp 项目结构、模块组织、测试方式和依赖管理方式，不要直接修改文件。

需要更多资料时，从 more-details 里的 mcpp docs、mcpp-index、mcpplibs/cmdline 等链接继续查。
保持 mcpp-only；测试遵循 mcpp test 规范；默认不要重新导出第三方依赖。
README 只做入口引导，细节放到 docs/architecture.md。
```

## More Information

- mcpp 工具与文档：https://github.com/mcpp-community/mcpp
- mcpp docs：https://github.com/mcpp-community/mcpp/tree/main/docs
- mcpp.toml 指南：https://github.com/mcpp-community/mcpp/blob/main/docs/05-mcpp-toml.md
- mcpp 包索引：https://github.com/mcpp-community/mcpp-index
- mcpplibs 组织：https://github.com/mcpplibs
- 模板仓库：https://github.com/mcpplibs/template
- 依赖库参考案例：https://github.com/mcpplibs/cmdline
- C++23 模块风格参考：https://github.com/mcpp-community/mcpp-style-ref
- xlings 工具环境：https://github.com/openxlings/xlings
