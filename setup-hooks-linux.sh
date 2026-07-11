#!/bin/sh

HOOK_SRC="$(pwd)/scripts/commit-msg"
HOOK_DEST=".git/hooks/commit-msg"

if rm -f "$HOOK_DEST" &&
   ln -s "$HOOK_SRC" "$HOOK_DEST" &&
   chmod +x "$HOOK_SRC"; then
    echo "Hooks 安装成功"
else
    echo "Hooks 安装失败" >&2
    exit 1
fi
