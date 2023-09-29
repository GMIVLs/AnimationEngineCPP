# vcpkg global script

- The following script is written in `python` which will allow us to get all the installed libraries in the `vcpkg` locally.

  - run this script at the directory of the `vcpkg`, which I installed at `$HOME/vcpkg/`
  - It will go and check all the installed packages that fetched locally for each given project as `$HOME/vcpkg/installed/`
  - For a given project, the libraries are installed at `vcpkg_installed` which will create a copy as well at `$HOME/vcpkge/installed`.
  - For global installtion assume you run `vcpkg install <pakcage_name>` it will be located at `$HOME/vcpkg/packages/`.

- The script is:

```python
import re

# Read the status file
with open("installed/vcpkg/status", "r") as f:
    content = f.read()

# Regular expression to capture package name and version
pattern = re.compile(r"^Package: (\w+).*?^Version: ([\w\.\-]+)", re.DOTALL | re.MULTILINE)

# Extract package names and versions
packages = pattern.findall(content)

# Create a manifest dictionary
manifest = {
    "name": "my-project",
    "version-string": "0.1.0",
    "dependencies": [{"name": pkg, "version>=": ver} for pkg, ver in packages]
}

# Write the manifest to a vcpkg.json file
with open("vcpkg.json", "w") as f:
    f.write(str(manifest).replace("'", '"'))

print("vcpkg.json generated successfully!")

```
