import paver
from paver.easy import *
import paver.setuputils
paver.setuputils.install_distutils_tasks()
from socket import gethostname
import os, sys
from os import environ

from sphinxcontrib import paverutils

# new 7/2019 changes
import pkg_resources
from runestone import get_master_url

sys.path.append(os.getcwd())

home_dir = os.getcwd()

project_name = "overview"

#master_url = None
#if master_url is None:
#    if 'RSHOST' in os.environ:
#        master_url = environ['RSHOST']
#    elif gethostname() in  ['web608.webfaction.com', 'rsbuilder']:
#        master_url = 'http://interactivepython.org'
#    elif gethostname() == 'runestone-deploy':
#        master_url = 'https://runestone.academy'
#    else:
#        master_url = 'http://127.0.0.1:8000'

# new 7/2019 changes
master_url = None

if master_url is None:
    master_url = get_master_url()

master_app = 'runestone'
serving_dir = "./build/overview"

#new 7/2019 changes
# Change to False when running localhost
dynamic_pages = False

if dynamic_pages:
    dest = './published'
else:
    dest = '../../static'

#master_app = 'runestone'
#serving_dir = "./build/StudentCSP"
#dest = '../../static'
#project_name = "StudentCSP"

options(
    sphinx = Bunch(docroot=".",),

    build = Bunch(
        builddir="./build/overview",
        sourcedir="_sources",
        outdir="./build/overview",
        confdir=".",
        project_name=project_name,
        template_args={'course_id': project_name,
                       'login_required':'false',
                       'appname':master_app,
                       'loglevel': 10,
                       'course_url':master_url,
                       'use_services': 'true',
                       'python3': 'true',
                       'dburl': 'postgresql://runestone@localhost/runestone',
                       'basecourse': 'overview',
                        # new 7/2019 changes
                       'dynamic_pages': dynamic_pages,
                       'downloads_enabled': 'false',
                       'enable_chatcodes': 'false',
                       'allow_pairs': 'true'
                        }
    )
)

# Check to see if we are building on our Jenkins build server, if so use the environment variables
# to update the DB information for this build
if 'DBHOST' in environ and  'DBPASS' in environ and 'DBUSER' in environ and 'DBNAME' in environ:
    options.build.template_args['dburl'] = 'postgresql://{DBUSER}:{DBPASS}@{DBHOST}/{DBNAME}'.format(**environ)

from runestone import build  # build is called implicitly by the paver driver.
