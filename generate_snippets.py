import os
import json
import sys

snippets = {}
template_dir = './template'
output_dir = '.vscode'
output_file = os.path.join(output_dir, 'cpp.code-snippets')

# 确保 .vscode 目录存在
os.makedirs(output_dir, exist_ok=True)

# 检查 template 目录是否存在
if not os.path.isdir(template_dir):
    print(f'❌ error: directory {template_dir} does not exist', file=sys.stderr)
    sys.exit(1)

# 遍历 template 目录下的所有 .cpp 文件
for filename in os.listdir(template_dir):
    if not filename.endswith('.cpp'):
        continue

    name = filename[:-4]  # 去掉 .cpp 后缀
    prefix = f'!{name}'   # prefix 加上感叹号

    if name in snippets:
        print(f'❌ error: duplicate snippet {name}', file=sys.stderr)
        sys.exit(1)

    path = os.path.join(template_dir, filename)
    with open(path, 'r') as f:
        snippet = {
            "prefix": prefix,
            "body": [line.rstrip() for line in f.readlines()],
            "description": name
        }
        snippets[name] = snippet

    print(f'✅ generated snippet {name}', file=sys.stderr)

# 写入到 .vscode/cpp.code-snippets
with open(output_file, 'w') as f:
    json.dump(snippets, f, indent=2)

print(f'🎉 snippets written to {output_file}', file=sys.stderr)
