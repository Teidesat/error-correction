#include "Source.h"

namespace FEC {
    template<size_t N>
    bool Source<N>::read(size_t data_blocks) {
        bool end_reached = false;
        for (size_t i = 0; i < data_blocks && !end_reached; i++) {
            DataBlock<N> data_block;
            end_reached = this->read_data_block(data_block);
            if (!end_reached) send_data_block(data_block);
        }
        return !end_reached;
    }

    template<size_t N>
    void Source<N>::read_all() {
        bool end_reached = false;
        while (!end_reached) {
            DataBlock<N> data_block;
            end_reached = this->read_data_block(data_block);
            if (!end_reached) send_data_block(data_block);
        }
    }

    template<size_t N>
    void Source<N>::send_data_block(DataBlock<N> &data_block) {
        auto db = std::make_shared<DataBlock<N>>(data_block);
        this->get_pipe().send_data(db);
    }
}
