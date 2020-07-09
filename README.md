# README

## Write a CMakeLists.txt

- `CMakeLists.txt` in root folder.\
/root:\
/build, /include, /src, CMakeLists.txt, README.md

- Add header files in `include` folder

- Add cpp files in `src` folder

- In `build` folder, run\
`cmake ..`\
`make`\
`./main`

- To delete `build` folder, run\
`rm -r build/-`

## Naming rules

The naming rules follow Google's style.

### File

- All lowercase, _ or - between words
- my_useful_class.cc

### Type

- Capital letter for each word
- MyUsefulClass

### Function

- Capital letter for each word
- AddTableEntry()

### Variable

- All lowercase, _ between words
- a_local_variable, a_struct_data_member
- a_class_data_member_

### Prefix

- b_
- k_
