import paver
from paver.easy import *
import paver.setuputils
paver.setuputils.install_distutils_tasks()
import os, sys
from socket import gethostname

from sphinxcontrib import paverutils


######## CHANGE THIS ##########
project_name = "overview"
###############################

master_url = None
if master_url is None:
    if gethostname() in ['web407.webfaction.com', 'rsbuilder']:
        master_url = 'http://interactivepython.org'
    else:
        master_url = 'http://127.0.0.1:8000'
master_app = 'runestone'
serving_dir = "./build/"+project_name
dest = '../../static'

options(
    sphinx = Bunch(docroot=".",),

    build = Bunch(
        builddir="./build/"+project_name,
        sourcedir=".",
        outdir="./build/"+project_name,
        confdir=".",
        project_name = project_name,
        template_args = {
            'course_id':project_name,
            'login_required':'false',
            'appname':master_app,
            'loglevel':10,
            'course_url':master_url,
            'use_services': 'true',
            'basecourse': 'overview',
            'python3': 'true',
        }
    )
)

from runestone import build  # build is called implicitly by the paver driver.
