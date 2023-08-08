FROM python:slim

RUN apt -y update && apt -y install git
RUN pip install pylint flake8 bandit
RUN pip install pytest coverage

RUN pip install autopep8 black yapf pycodestyle pydocstyle

RUN pip install sphinx sphinx-rtd-theme
RUN apt -y install diffutils patch make doxygen

WORKDIR /mnt
