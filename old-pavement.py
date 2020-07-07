import paver
from paver.easy import *
import paver.setuputils

paver.setuputils.install_distutils_tasks()
import os, sys
from socket import gethostname
import pkg_resources
from sphinxcontrib import paverutils


######## CHANGE THIS ##########
project_name = "overview"
###############################

master_url = "https://runestone.academy"
if master_url is None:
    if gethostname() in ["runestone.academy", "runestone-deploy", "rsbuilder"]:
        master_url = "https://runestone.academy"
    elif "RUNESTONE_HOST" in os.environ:
        master_url = "http://{}".format(os.environ["RUNESTONE_HOST"])
    else:
        master_url = "http://127.0.0.1:8000"

master_app = "runestone"
serving_dir = "./build/" + project_name
dest = "./published"

options(
    sphinx=Bunch(docroot=".",),
    build=Bunch(
        builddir="./build/" + project_name,
        sourcedir="_sources",
        outdir="./build/" + project_name,
        confdir=".",
        project_name=project_name,
        template_args={
            "course_id": project_name,
            "login_required": "false",
            "appname": master_app,
            "loglevel": 10,
            "course_url": master_url,
            "dynamic_pages": True,
            "use_services": "true",
            "basecourse": "overview",
            "python3": "true",
            "downloads_enabled": "true",
            "allow_pairs": "false",
            "enable_chatcodes": "false",
        },
    ),
)

version = pkg_resources.require("runestone")[0].version
options.build.template_args["runestone_version"] = version

from runestone import build  # build is called implicitly by the paver driver.
