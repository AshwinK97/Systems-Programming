@echo off
:calledRoutine
setlocal

%@Try%
	devenv.exe
%@EndTry%
:@catch
	echo "problem1: could not use 'devenv' command"
	%@Try%
		