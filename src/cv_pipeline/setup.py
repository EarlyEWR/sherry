from setuptools import setup

package_name = "cv_pipeline"

setup(
    name=package_name,
    version="0.0.1",
    packages=[package_name],
    data_files=[
        ("share/ament_index/resource_index/packages", ["resource/" + package_name]),
        ("share/" + package_name, ["package.xml"]),
        ("share/" + package_name + "/config", ["config/cv_params.yaml"]),
    ],
    install_requires=["setuptools"],
    zip_safe=True,
    entry_points={
        "console_scripts": [
            "basilisk_camera_node = cv_pipeline.basilisk_camera_node:main",
            "cv_pipeline_node = cv_pipeline.cv_pipeline_node:main",
        ],
    },
)