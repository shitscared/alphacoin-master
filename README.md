Alphacoin - a fork of Litecoin version. Like Litecoin it uses scrypt as a proof of work scheme.

	- Total coins will be 210,182,000.
	- 30 sec block target
	- 4 transaction confirmation, so it's 2 mins confirmation time for transactions.
	- Difficulty retargets every 30 mins
	- To encorage early adoption the coins per block is high for the first 3 days (block time):
		- 1st day: 500 coins per block
		- 2nd day: 200 coins per block
		- 3rd day: 100 coins per block
	- Starting 4th day, it will be 50 coins per block, will be halved every two years (or 2073600 blocks).
	- First 1000 special blocks of 1000 coins each are premined. This is used for bounty of various needs. Also the 1000 blocks are used for checkpoints.

	- The default ports are 9538(connect) and 9539(json rpc).


Development process
===================

Developers work in their own trees, then submit pull requests when
they think their feature or bug fix is ready.

The patch will be accepted if there is broad consensus that it is a
good thing.  Developers should expect to rework and resubmit patches
if they don't match the project's coding conventions (see coding.txt)
or are controversial.

The master branch is regularly built and tested, but is not guaranteed
to be completely stable. Tags are regularly created to indicate new
official, stable release versions of Litecoin.

Feature branches are created when there are major new features being
worked on by several people.

From time to time a pull request will become outdated. If this occurs, and
the pull is no longer automatically mergeable; a comment on the pull will
be used to issue a warning of closure. The pull will be closed 15 days
after the warning if action is not taken by the author. Pull requests closed
in this manner will have their corresponding issue labeled 'stagnant'.

Issues with no commits will be given a similar warning, and closed after
15 days from their last activity. Issues closed in this manner will be 
labeled 'stale'. 
