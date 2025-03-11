from setuptools import find_packages
from setuptools import setup

setup(
    name='xsmmsg',
    version='0.0.0',
    packages=find_packages(
        include=('xsmmsg', 'xsmmsg.*')),
)
