---
name: more-details
description: 为 mcpp/mcpplibs 模块库开发提供资料导航。适用于 Agent 需要了解 mcpp 工具、mcpp.toml、包索引、mcpplibs 生态、依赖案例、xlings 工具环境、或寻找更多外部资料链接时。
---

# more-details

这是 mcpp/mcpplibs 模块库开发的资料入口 skill。它只负责引导 Agent 去哪里查资料；具体实现仍以本仓库文件、mcpp 官方文档和实际命令输出为准。

## 使用原则

- 先看本仓库入口，再跳外部资料。
- 只读取当前任务需要的文档，不要一次性展开所有链接。
- 涉及工具行为、包版本、索引内容时，以当前仓库文件和外部源的最新内容为准。
- 写 C++23 模块代码时，同时使用 `mcpp-style-ref`。

## 本仓库入口

- `README.md`：模板使用入口、AI Agent 提示词、外部资源链接。
- `docs/architecture.md`：项目结构、mcpp 约定、依赖添加方式。
- `.xlings.json`：声明项目工具环境。
- `mcpp.toml`：包信息、依赖和测试依赖。
- `src/mylib.cppm`：库模块接口示例。
- `tests/mylib_test.cpp`：符合 mcpp 规范的 gtest 测试示例。
- `examples/basic/`：独立使用方示例。

## 外部资源

### mcpp 工具

- mcpp 仓库：https://github.com/mcpp-community/mcpp
- mcpp 文档：https://github.com/mcpp-community/mcpp/tree/main/docs
- 快速开始：https://github.com/mcpp-community/mcpp/blob/main/docs/00-getting-started.md
- 示例文档：https://github.com/mcpp-community/mcpp/blob/main/docs/01-examples.md
- `mcpp.toml` 指南：https://github.com/mcpp-community/mcpp/blob/main/docs/05-mcpp-toml.md

优先用这些资料确认：

- `mcpp build`、`mcpp test`、`mcpp run` 的行为。
- `src/*.cppm`、`src/main.cpp`、`tests/**/*.cpp` 的默认推断规则。
- `[dependencies]`、`[dependencies.<namespace>]`、`[dev-dependencies]` 和目标覆盖配置。

### 包索引与生态

- mcpp 包索引：https://github.com/mcpp-community/mcpp-index
- mcpplibs 组织：https://github.com/mcpplibs
- 依赖库参考案例：https://github.com/mcpplibs/cmdline

添加依赖时优先检查包索引；需要看真实库写法时参考 `mcpplibs/cmdline`。默认直接 `import <module>;`，不要在主模块里默认 `export import` 依赖。

### 编码风格

- mcpp-style-ref 仓库：https://github.com/mcpp-community/mcpp-style-ref
- 本仓库风格 skill：`.agents/skills/mcpp-style-ref/SKILL.md`

写或改 `.cppm` / `.cpp` 文件时，遵循 C++23 模块风格：`import std`、模块名稳定、公开 API 简洁、测试不写自定义 `main()`。

### 工具环境

- xlings：https://github.com/openxlings/xlings

本模板通过 `.xlings.json` 声明项目工具环境。进入仓库后通常使用：

```bash
xlings install
export PATH="$PWD/.xlings/subos/_/bin:$PATH"
mcpp --version
```

## 常见任务指引

- **了解模板结构**：读 `README.md` 和 `docs/architecture.md`。
- **确认 mcpp 配置写法**：读 `mcpp.toml` 和 mcpp 的 `05-mcpp-toml.md`。
- **新增依赖**：查 `mcpp-index`，再参考 `mcpplibs/cmdline`。
- **新增模块 API**：读 `mcpp-style-ref`，再改 `src/*.cppm`。
- **新增测试**：参考 `tests/mylib_test.cpp`，用 `mcpp test` 验证。
- **新增示例**：参考 `examples/basic/`，用独立 `mcpp.toml` 和 path 依赖。
