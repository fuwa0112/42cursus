#!/usr/bin/env python3

import re
from pathlib import Path

FILES = (
list(Path("inc").rglob("*.h"))
+ list(Path("inc").rglob("*.c"))
+ list(Path("src").rglob("*.h"))
+ list(Path("src").rglob("*.c"))
)

REPLACE = {
"thaperei": "thitoe",
"hermarti": "hakama",
"[marvin@42.fr](mailto:marvin@42.fr)": "[thitoe@student.42tokyo.jp](mailto:thitoe@student.42tokyo.jp)",
"[hermarti@student.42sp.org.br](mailto:hermarti@student.42sp.org.br)": "[hakama@student.42tokyo.jp](mailto:hakama@student.42tokyo.jp)",
}

for path in FILES:
	text = path.read_text()
	lines = text.splitlines()

for i, line in enumerate(lines):

    if "By:" in line and "<" in line and ">" in line:
        m = re.match(
            r"(/\*\s+By:\s+)([^<]+)(<[^>]+>)(.*\+#+#+#+#+\s+#+#+#+#+\s+\*/)",
            line
        )
        if m:
            prefix, name, mail, suffix = m.groups()

            name = name.strip()
            mail = mail[1:-1]

            name = REPLACE.get(name, name)
            mail = REPLACE.get(mail, mail)

            left = f"{prefix}{name} <{mail}>"
            spaces = max(1, 80 - len(left) - len(suffix))
            lines[i] = left + (" " * spaces) + suffix

    elif "Created:" in line:
        m = re.match(
            r"(/\*\s+Created:\s+.*?\s+by\s+)(\w+)(.*#\+\s+#\+\s+\*/)",
            line
        )
        if m:
            prefix, user, suffix = m.groups()

            user = REPLACE.get(user, user)

            left = prefix + user
            spaces = max(1, 80 - len(left) - len(suffix))
            lines[i] = left + (" " * spaces) + suffix

    elif "Updated:" in line:
        m = re.match(
            r"(/\*\s+Updated:\s+.*?\s+by\s+)(\w+)(.*###\s+########\.fr\s+\*/)",
            line
        )
        if m:
            prefix, user, suffix = m.groups()

            user = REPLACE.get(user, user)

            left = prefix + user
            spaces = max(1, 80 - len(left) - len(suffix))
            lines[i] = left + (" " * spaces) + suffix

path.write_text("\n".join(lines) + "\n")

print("42 header update complete.")
