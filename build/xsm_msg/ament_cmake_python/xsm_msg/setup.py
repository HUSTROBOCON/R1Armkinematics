from setuptools import find_packages
from setuptools import setup

setup(
    name='xsm_msg',
    version='0.0.0',
    packages=find_packages(
        include=('xsm_msg', 'xsm_msg.*')),
)
