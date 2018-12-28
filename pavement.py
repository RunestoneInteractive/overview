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

master_url = 'https://runestone.academy'
if master_url is None:
    if gethostname() in ['runestone.academy', 'runestone-deploy',  'rsbuilder']:
        master_url = 'https://runestone.academy'
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
            'downloads_enabled': 'true',
            'jobe_server': master_url,
            'proxy_uri_runs': '/runestone/proxy/jobeRun',
            'proxy_uri_files': '/runestone/proxy/jobePushFile',
        }
    )
)

from runestone import build  # build is called implicitly by the paver driver.
