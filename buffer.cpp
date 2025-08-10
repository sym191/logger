// //
// // Created by anon on 25-8-9.
// //

// #include "buffer.h"

// void buffer::push(const std::string& filename, const std::string& message)
// {
//     _buffer.emplace_back(message, filename);
//     if (message.size() > _data.capacity() - _cur_size)
//     {
//         _data.reserve(_cur_size + message.size());
//     }
//     memcpy(_data.data() + _cur_size, message.data(), message.size());
//     _cur_size += message.size();
// }

// void buffer::push(buffer& buf)
// {

// }
