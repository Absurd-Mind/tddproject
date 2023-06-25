# TDDProject

## Initial start

Install and compile the project with conan for the very first time:

```shell
conan install . -s build_type=Debug
conan build . -s build_type=Debug
```

After that you can just use cmake to rebuild targets or use `conan build`
