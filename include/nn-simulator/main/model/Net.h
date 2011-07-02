/* 
 * File:   Net.h
 * Author: Will
 *
 * Created on 08 June 2011, 16:36
 */

#ifndef NET_H
#define	NET_H

#include "Architecture.h"
#include "Layer.h"
#include "model/exceptions/IncorrectInputException.h"
#include "util/exceptions/UnsupportedConfigurationException.h"
#include "util/exceptions/IllegalArgumentException.h"

/**
 * The network class. That is, a store of 
 * <code>Layer</code>s that may not exceed that maximum
 * number of supported <code>Layer</code>s of the implemented
 * <code>Architecture</code>.
 * 
 */
class Net {
public:
    /**
     * Default constructor.
     * 
     * @param a the <code>Architecture</code> that this <code>Net</code>
     * implements.
     * @param noLayers the number of <code>Layer</code>s that this
     * <code>Net</code> should have.
     * @throw UnsupportedConfigurationException if the number of layers
     * or inputs does not match a supported configuration.
     * @throw IllegalArgumentException if any of the arguments are illegal
     * i.e. if the <code>Architecture</code> is NULL.
     * 
     */
    Net(Architecture *a, int noLayers, int noInputs)
    throw (UnsupportedConfigurationException*, IllegalArgumentException*);
    virtual ~Net();
    /**
     * Gets the number of <code>Layer</code>s of this <code>Net</code>.
     * 
     * @return the number of <code>Layer</code>s of this 
     * <code>Net</code>.
     * 
     */
    int getSize();
    /**
     * Sets the <code>Layer</code> at the specified position to be 
     * the given <code>Architecture</code>.
     * 
     * @param i the position to set the <code>Layer</code> at.
     * @param newLayer the <code>Layer</code> to set.
     * 
     */
    void setLayer(int i, Layer *newLayer);
    /**
     * Gets the <code>Layer</code> at the specified position.
     * 
     * @param i the position to get the <code>Layer</code> from.
     * @return the <code>Layer</code> at the specified position.
     * 
     */
    Layer *getLayer(int i);
    /**
     * Gets the <code>Architecture</code> that this <code>Net</code>
     * implements.
     * 
     * @return the <code>Architecture</code> that this <code>Net</code>
     * implements.
     * 
     */
    Architecture *getArchitecture();
    /**
     * Gets the number of inputs that this <code>Net</code> receives.
     * 
     * @return the number of inputs that this <code>Net</code> receives.
     * 
     */
    int getNoInputs();
    /**
     * Processes the given <code>Input</code> to produce this 
     * <code>Net</code>'s <code>Output</code>.
     * 
     * @param input the <code>Input</code> to process.
     * @return the <code>Output</code> from the given 
     * <code>Input</code>.
     * 
     */
    Output *processInput(Input *input) throw (IncorrectInputException*);
protected:
    /**
     * Sets the number of inputs that this <code>Net</code> receives.
     * 
     * @param noInputs the number of inputs that this <code>Net</code> receives.
     * 
     */
    void setNoInputs(int noInputs);
private:
    int size, noInputs;
    Layer **layers;
    Architecture *architecture;
};

#endif	/* NET_H */
