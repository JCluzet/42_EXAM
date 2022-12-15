#!/bin/bash

RENDU_DIR=$ROOT/rendu
GRADING_DIR=$ROOT/.system/grading
SERVER_DIR=$ROOT/.git_server.git

# create server
rm -rf $SERVER_DIR
mkdir $SERVER_DIR
git init --bare $SERVER_DIR &>/dev/null

# create rendu
mkdir $RENDU_DIR &>/dev/null
cd $RENDU_DIR
git init &>/dev/null
git remote add origin $SERVER_DIR

# create grading
mkdir $GRADING_DIR &>/dev/null
cd $GRADING_DIR
git init &>/dev/null
git remote add origin $SERVER_DIR
