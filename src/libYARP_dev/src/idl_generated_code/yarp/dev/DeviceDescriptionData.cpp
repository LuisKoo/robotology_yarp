/*
 * SPDX-FileCopyrightText: 2006-2021 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: BSD-3-Clause
 */

// Autogenerated by Thrift Compiler (0.14.1-yarped)
//
// This is an automatically generated file.
// It could get re-generated if the ALLOW_IDL_GENERATION flag is on.

#include <yarp/dev/DeviceDescriptionData.h>

namespace yarp::dev {

// Constructor with field values
DeviceDescriptionData::DeviceDescriptionData(const std::string& device_name,
                                             const std::string& device_type) :
        WirePortable(),
        device_name(device_name),
        device_type(device_type)
{
}

// Read structure on a Wire
bool DeviceDescriptionData::read(yarp::os::idl::WireReader& reader)
{
    if (!read_device_name(reader)) {
        return false;
    }
    if (!read_device_type(reader)) {
        return false;
    }
    if (reader.isError()) {
        return false;
    }
    return true;
}

// Read structure on a Connection
bool DeviceDescriptionData::read(yarp::os::ConnectionReader& connection)
{
    yarp::os::idl::WireReader reader(connection);
    if (!reader.readListHeader(2)) {
        return false;
    }
    if (!read(reader)) {
        return false;
    }
    return true;
}

// Write structure on a Wire
bool DeviceDescriptionData::write(const yarp::os::idl::WireWriter& writer) const
{
    if (!write_device_name(writer)) {
        return false;
    }
    if (!write_device_type(writer)) {
        return false;
    }
    if (writer.isError()) {
        return false;
    }
    return true;
}

// Write structure on a Connection
bool DeviceDescriptionData::write(yarp::os::ConnectionWriter& connection) const
{
    yarp::os::idl::WireWriter writer(connection);
    if (!writer.writeListHeader(2)) {
        return false;
    }
    if (!write(writer)) {
        return false;
    }
    return true;
}

// Convert to a printable string
std::string DeviceDescriptionData::toString() const
{
    yarp::os::Bottle b;
    if (!yarp::os::Portable::copyPortable(*this, b)) {
        return {};
    }
    return b.toString();
}

// read device_name field
bool DeviceDescriptionData::read_device_name(yarp::os::idl::WireReader& reader)
{
    if (reader.noMore()) {
        reader.fail();
        return false;
    }
    if (!reader.readString(device_name)) {
        reader.fail();
        return false;
    }
    return true;
}

// write device_name field
bool DeviceDescriptionData::write_device_name(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeString(device_name)) {
        return false;
    }
    return true;
}

// read (nested) device_name field
bool DeviceDescriptionData::nested_read_device_name(yarp::os::idl::WireReader& reader)
{
    if (reader.noMore()) {
        reader.fail();
        return false;
    }
    if (!reader.readString(device_name)) {
        reader.fail();
        return false;
    }
    return true;
}

// write (nested) device_name field
bool DeviceDescriptionData::nested_write_device_name(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeString(device_name)) {
        return false;
    }
    return true;
}

// read device_type field
bool DeviceDescriptionData::read_device_type(yarp::os::idl::WireReader& reader)
{
    if (reader.noMore()) {
        reader.fail();
        return false;
    }
    if (!reader.readString(device_type)) {
        reader.fail();
        return false;
    }
    return true;
}

// write device_type field
bool DeviceDescriptionData::write_device_type(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeString(device_type)) {
        return false;
    }
    return true;
}

// read (nested) device_type field
bool DeviceDescriptionData::nested_read_device_type(yarp::os::idl::WireReader& reader)
{
    if (reader.noMore()) {
        reader.fail();
        return false;
    }
    if (!reader.readString(device_type)) {
        reader.fail();
        return false;
    }
    return true;
}

// write (nested) device_type field
bool DeviceDescriptionData::nested_write_device_type(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeString(device_type)) {
        return false;
    }
    return true;
}

} // namespace yarp::dev
