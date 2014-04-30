// Copyright (c) 2009-2012 The Bitcoin developers
// Copyright (c) 2011-2012 Litecoin Developers
// Copyright (c) 2013 Alphacoin Developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "checkpoints.h"

#include "main.h"
#include "uint256.h"

namespace Checkpoints
{
    typedef std::map<int, uint256> MapCheckpoints;

    //
    // What makes a good checkpoint block?
    // + Is surrounded by blocks with reasonable timestamps
    //   (no blocks before with a timestamp after, none after with
    //    timestamp before)
    // + Contains no strange transactions
    //

	// no checkpoint now, can be added in later releases
    static MapCheckpoints mapCheckpoints =
            boost::assign::map_list_of
            (    1, uint256("0xf9d50cbbef478637504e011d39b38a73cabb09a2a0f1c920e47808d95175c6fe"))
            (   87, uint256("0x8d4a78e2a96123e632f41fce4c08bb24bc178cf3e815e7bc1a573cc22bf26bde"))
            (  458, uint256("0xfaa23e88797bd92058f7ac7b04042e298384ed03988e3b16410a35177cfb07bc"))
            (  729, uint256("0xefa152e0f3e8d96f9b7b7b700d85edc3051256c12bacea6ae84a0f7619f5fbbd"))
            ( 1000, uint256("0xc3da5ce412978194792fb7df31e4c9d5d984aa4996831e1ecedb867795dff8e0"))
            (34920, uint256("0x892e9699703058ff38e4cc19c9c276dd5dd5d0f3ba590fe26bb3a25757362139"))
            (35388, uint256("0xe4b4c22712c949866cff74f3efc055b7b651555c9130b5019ca272f917387a3a"))
			;

    bool CheckBlock(int nHeight, const uint256& hash)
    {
        if (fTestNet) return true; // Testnet has no checkpoints

        MapCheckpoints::const_iterator i = mapCheckpoints.find(nHeight);
        if (i == mapCheckpoints.end()) return true;
        return hash == i->second;
    }

    int GetTotalBlocksEstimate()
    {
        if (fTestNet) return 0;
	
        return mapCheckpoints.rbegin()->first;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        if (fTestNet) return NULL;

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, mapCheckpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
                return t->second;
        }
        return NULL;
    }
}
