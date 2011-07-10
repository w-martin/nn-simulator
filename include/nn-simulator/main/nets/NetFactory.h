/* 
 * File:   NetFactory.h
 * Author: will
 *
 * Created on July 9, 2011, 8:10 PM
 */

#ifndef NETFACTORY_H
#define	NETFACTORY_H

#include "nn-simulator/main/util/Factory.h"
#include "nn-simulator/main/model/Net.h"
#include "nn-simulator/main/nets/BDN/realisations/ORnet.h"
#include <string>

template<>
class Factory<Net, const char*> {
public:
    /**
     * Creates an instance of the <code>Net</code> specified by the
     * given netType.
     * 
     * @param netType the identifier of the net to create.
     * @param size the size the net should be.
     * @return an auto pointer to the created net, to transfer
     * ownership to the caller.
     * @throw UnsupportedConfigurationException if the net is unknown.
     * 
     */
    static auto_ptr<Net> createInstance(const char* netType,
            const int &size)
    throw (UnsupportedConfigurationException) {
        if (0 == strcmp(NET_TYPE_ORNET, netType)) {
            return auto_ptr<Net > (new ORnet(size));
        }
        throw UnsupportedConfigurationException("Error. Unknown net.");
    }
};

#endif	/* NETFACTORY_H */
