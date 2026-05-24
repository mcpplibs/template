# 架构文档

> 一个最小 mcpp C++23 模块库模板。

## 目标

仓库只表达三件事：

- 用 `.xlings.json` 声明项目工具环境。
- 用 `mcpp.toml` 声明 C++23 模块库和测试依赖；运行时依赖按需添加。
- 用 `mcpp build`、`mcpp test`、`mcpp run` 验证库、单元测试和示例。

## mcpp 约定

- 默认扫描 `src/**/*.{cppm,cpp,cc,c}`。
- 只有 `src/*.cppm` 且没有 `src/main.cpp` 时，mcpp 会自动推断库目标；需要覆盖默认行为时再显式写 `[targets.<name>]`。
- 库根模块默认放在 `src/<package-name>.cppm`。
- 依赖放 `[dependencies]` 或 `[dependencies.<namespace>]`。
- 测试依赖放 `[dev-dependencies]`。
- 单元测试放 `tests/**/*.cpp`，由 `mcpp test` 自动发现；测试文件只写 `TEST(...)`，不定义 `main()`。

## 当前结构

```text
.
├── .xlings.json
├── mcpp.toml
├── src/mylib.cppm
├── tests/mylib_test.cpp
└── examples/basic/
    ├── mcpp.toml
    └── src/main.cpp
```

## 根包

```toml
[package]
namespace = "mcpplibs"
name      = "mylib"
version   = "0.1.0"

[dev-dependencies]
gtest = "1.15.2"
```

`src/mylib.cppm` 导出 `mcpplibs.mylib`。mcpp 会从这个 `.cppm` 自动推断 `mylib` 库目标，默认不重新导出任何第三方模块。

## 添加依赖

需要依赖其他 mcpp 包时，在根 `mcpp.toml` 添加依赖声明：

```toml
[dependencies.mcpplibs]
cmdline = "0.0.2"
```

模块实现里按需导入：

```cpp
import mcpplibs.cmdline;
```

不推荐默认使用 `export import` 做二级暴露。只有公开 API 直接暴露依赖包类型时，才考虑重新导出。

## 示例包

`examples/basic` 是独立 mcpp 包，通过 path 依赖引用根库：

```toml
[dependencies.mcpplibs]
mylib = { path = "../.." }
```

运行：

```bash
cd examples/basic
mcpp run
```

## CI

CI 做同一条路径：

```bash
xlings install -y
mcpp build
mcpp test
cd examples/basic && mcpp run
```
