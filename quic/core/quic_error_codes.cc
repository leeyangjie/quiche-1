// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "net/third_party/quiche/src/quic/core/quic_error_codes.h"
#include "third_party/boringssl/src/include/openssl/ssl.h"
#include "net/third_party/quiche/src/quic/platform/api/quic_logging.h"
#include "net/third_party/quiche/src/common/platform/api/quiche_str_cat.h"

namespace quic {

#define RETURN_STRING_LITERAL(x) \
  case x:                        \
    return #x;

const char* QuicRstStreamErrorCodeToString(QuicRstStreamErrorCode error) {
  switch (error) {
    RETURN_STRING_LITERAL(QUIC_STREAM_NO_ERROR);
    RETURN_STRING_LITERAL(QUIC_ERROR_PROCESSING_STREAM);
    RETURN_STRING_LITERAL(QUIC_MULTIPLE_TERMINATION_OFFSETS);
    RETURN_STRING_LITERAL(QUIC_BAD_APPLICATION_PAYLOAD);
    RETURN_STRING_LITERAL(QUIC_STREAM_CONNECTION_ERROR);
    RETURN_STRING_LITERAL(QUIC_STREAM_PEER_GOING_AWAY);
    RETURN_STRING_LITERAL(QUIC_STREAM_CANCELLED);
    RETURN_STRING_LITERAL(QUIC_RST_ACKNOWLEDGEMENT);
    RETURN_STRING_LITERAL(QUIC_REFUSED_STREAM);
    RETURN_STRING_LITERAL(QUIC_INVALID_PROMISE_URL);
    RETURN_STRING_LITERAL(QUIC_UNAUTHORIZED_PROMISE_URL);
    RETURN_STRING_LITERAL(QUIC_DUPLICATE_PROMISE_URL);
    RETURN_STRING_LITERAL(QUIC_PROMISE_VARY_MISMATCH);
    RETURN_STRING_LITERAL(QUIC_INVALID_PROMISE_METHOD);
    RETURN_STRING_LITERAL(QUIC_PUSH_STREAM_TIMED_OUT);
    RETURN_STRING_LITERAL(QUIC_HEADERS_TOO_LARGE);
    RETURN_STRING_LITERAL(QUIC_STREAM_TTL_EXPIRED);
    RETURN_STRING_LITERAL(QUIC_DATA_AFTER_CLOSE_OFFSET);
    RETURN_STRING_LITERAL(QUIC_STREAM_GENERAL_PROTOCOL_ERROR);
    RETURN_STRING_LITERAL(QUIC_STREAM_INTERNAL_ERROR);
    RETURN_STRING_LITERAL(QUIC_STREAM_STREAM_CREATION_ERROR);
    RETURN_STRING_LITERAL(QUIC_STREAM_CLOSED_CRITICAL_STREAM);
    RETURN_STRING_LITERAL(QUIC_STREAM_FRAME_UNEXPECTED);
    RETURN_STRING_LITERAL(QUIC_STREAM_FRAME_ERROR);
    RETURN_STRING_LITERAL(QUIC_STREAM_EXCESSIVE_LOAD);
    RETURN_STRING_LITERAL(QUIC_STREAM_ID_ERROR);
    RETURN_STRING_LITERAL(QUIC_STREAM_SETTINGS_ERROR);
    RETURN_STRING_LITERAL(QUIC_STREAM_MISSING_SETTINGS);
    RETURN_STRING_LITERAL(QUIC_STREAM_REQUEST_REJECTED);
    RETURN_STRING_LITERAL(QUIC_STREAM_REQUEST_INCOMPLETE);
    RETURN_STRING_LITERAL(QUIC_STREAM_CONNECT_ERROR);
    RETURN_STRING_LITERAL(QUIC_STREAM_VERSION_FALLBACK);
    RETURN_STRING_LITERAL(QUIC_STREAM_DECOMPRESSION_FAILED);
    RETURN_STRING_LITERAL(QUIC_STREAM_ENCODER_STREAM_ERROR);
    RETURN_STRING_LITERAL(QUIC_STREAM_DECODER_STREAM_ERROR);
    RETURN_STRING_LITERAL(QUIC_STREAM_UNKNOWN_APPLICATION_ERRROR_CODE);
    RETURN_STRING_LITERAL(QUIC_STREAM_LAST_ERROR);
  }
  // Return a default value so that we return this when |error| doesn't match
  // any of the QuicRstStreamErrorCodes. This can happen when the RstStream
  // frame sent by the peer (attacker) has invalid error code.
  return "INVALID_RST_STREAM_ERROR_CODE";
}

const char* QuicErrorCodeToString(QuicErrorCode error) {
  switch (error) {
    RETURN_STRING_LITERAL(QUIC_NO_ERROR);
    RETURN_STRING_LITERAL(QUIC_INTERNAL_ERROR);
    RETURN_STRING_LITERAL(QUIC_STREAM_DATA_AFTER_TERMINATION);
    RETURN_STRING_LITERAL(QUIC_INVALID_PACKET_HEADER);
    RETURN_STRING_LITERAL(QUIC_INVALID_FRAME_DATA);
    RETURN_STRING_LITERAL(QUIC_MISSING_PAYLOAD);
    RETURN_STRING_LITERAL(QUIC_INVALID_FEC_DATA);
    RETURN_STRING_LITERAL(QUIC_INVALID_STREAM_DATA);
    RETURN_STRING_LITERAL(QUIC_OVERLAPPING_STREAM_DATA);
    RETURN_STRING_LITERAL(QUIC_UNENCRYPTED_STREAM_DATA);
    RETURN_STRING_LITERAL(QUIC_INVALID_RST_STREAM_DATA);
    RETURN_STRING_LITERAL(QUIC_INVALID_CONNECTION_CLOSE_DATA);
    RETURN_STRING_LITERAL(QUIC_INVALID_GOAWAY_DATA);
    RETURN_STRING_LITERAL(QUIC_INVALID_WINDOW_UPDATE_DATA);
    RETURN_STRING_LITERAL(QUIC_INVALID_BLOCKED_DATA);
    RETURN_STRING_LITERAL(QUIC_INVALID_STOP_WAITING_DATA);
    RETURN_STRING_LITERAL(QUIC_INVALID_PATH_CLOSE_DATA);
    RETURN_STRING_LITERAL(QUIC_INVALID_ACK_DATA);
    RETURN_STRING_LITERAL(QUIC_INVALID_VERSION_NEGOTIATION_PACKET);
    RETURN_STRING_LITERAL(QUIC_INVALID_PUBLIC_RST_PACKET);
    RETURN_STRING_LITERAL(QUIC_DECRYPTION_FAILURE);
    RETURN_STRING_LITERAL(QUIC_ENCRYPTION_FAILURE);
    RETURN_STRING_LITERAL(QUIC_PACKET_TOO_LARGE);
    RETURN_STRING_LITERAL(QUIC_PEER_GOING_AWAY);
    RETURN_STRING_LITERAL(QUIC_HANDSHAKE_FAILED);
    RETURN_STRING_LITERAL(QUIC_CRYPTO_TAGS_OUT_OF_ORDER);
    RETURN_STRING_LITERAL(QUIC_CRYPTO_TOO_MANY_ENTRIES);
    RETURN_STRING_LITERAL(QUIC_CRYPTO_TOO_MANY_REJECTS);
    RETURN_STRING_LITERAL(QUIC_CRYPTO_INVALID_VALUE_LENGTH)
    RETURN_STRING_LITERAL(QUIC_CRYPTO_MESSAGE_AFTER_HANDSHAKE_COMPLETE);
    RETURN_STRING_LITERAL(QUIC_CRYPTO_INTERNAL_ERROR);
    RETURN_STRING_LITERAL(QUIC_CRYPTO_VERSION_NOT_SUPPORTED);
    RETURN_STRING_LITERAL(QUIC_CRYPTO_NO_SUPPORT);
    RETURN_STRING_LITERAL(QUIC_INVALID_CRYPTO_MESSAGE_TYPE);
    RETURN_STRING_LITERAL(QUIC_INVALID_CRYPTO_MESSAGE_PARAMETER);
    RETURN_STRING_LITERAL(QUIC_CRYPTO_MESSAGE_PARAMETER_NOT_FOUND);
    RETURN_STRING_LITERAL(QUIC_CRYPTO_MESSAGE_PARAMETER_NO_OVERLAP);
    RETURN_STRING_LITERAL(QUIC_CRYPTO_MESSAGE_INDEX_NOT_FOUND);
    RETURN_STRING_LITERAL(QUIC_UNSUPPORTED_PROOF_DEMAND);
    RETURN_STRING_LITERAL(QUIC_INVALID_STREAM_ID);
    RETURN_STRING_LITERAL(QUIC_INVALID_PRIORITY);
    RETURN_STRING_LITERAL(QUIC_TOO_MANY_OPEN_STREAMS);
    RETURN_STRING_LITERAL(QUIC_PUBLIC_RESET);
    RETURN_STRING_LITERAL(QUIC_INVALID_VERSION);
    RETURN_STRING_LITERAL(QUIC_INVALID_HEADER_ID);
    RETURN_STRING_LITERAL(QUIC_INVALID_NEGOTIATED_VALUE);
    RETURN_STRING_LITERAL(QUIC_DECOMPRESSION_FAILURE);
    RETURN_STRING_LITERAL(QUIC_NETWORK_IDLE_TIMEOUT);
    RETURN_STRING_LITERAL(QUIC_HANDSHAKE_TIMEOUT);
    RETURN_STRING_LITERAL(QUIC_ERROR_MIGRATING_ADDRESS);
    RETURN_STRING_LITERAL(QUIC_ERROR_MIGRATING_PORT);
    RETURN_STRING_LITERAL(QUIC_PACKET_WRITE_ERROR);
    RETURN_STRING_LITERAL(QUIC_PACKET_READ_ERROR);
    RETURN_STRING_LITERAL(QUIC_EMPTY_STREAM_FRAME_NO_FIN);
    RETURN_STRING_LITERAL(QUIC_INVALID_HEADERS_STREAM_DATA);
    RETURN_STRING_LITERAL(QUIC_HEADERS_STREAM_DATA_DECOMPRESS_FAILURE);
    RETURN_STRING_LITERAL(QUIC_FLOW_CONTROL_RECEIVED_TOO_MUCH_DATA);
    RETURN_STRING_LITERAL(QUIC_FLOW_CONTROL_SENT_TOO_MUCH_DATA);
    RETURN_STRING_LITERAL(QUIC_FLOW_CONTROL_INVALID_WINDOW);
    RETURN_STRING_LITERAL(QUIC_CONNECTION_IP_POOLED);
    RETURN_STRING_LITERAL(QUIC_PROOF_INVALID);
    RETURN_STRING_LITERAL(QUIC_CRYPTO_DUPLICATE_TAG);
    RETURN_STRING_LITERAL(QUIC_CRYPTO_ENCRYPTION_LEVEL_INCORRECT);
    RETURN_STRING_LITERAL(QUIC_CRYPTO_SERVER_CONFIG_EXPIRED);
    RETURN_STRING_LITERAL(QUIC_INVALID_CHANNEL_ID_SIGNATURE);
    RETURN_STRING_LITERAL(QUIC_CRYPTO_SYMMETRIC_KEY_SETUP_FAILED);
    RETURN_STRING_LITERAL(QUIC_CRYPTO_MESSAGE_WHILE_VALIDATING_CLIENT_HELLO);
    RETURN_STRING_LITERAL(QUIC_CRYPTO_UPDATE_BEFORE_HANDSHAKE_COMPLETE);
    RETURN_STRING_LITERAL(QUIC_VERSION_NEGOTIATION_MISMATCH);
    RETURN_STRING_LITERAL(QUIC_TOO_MANY_OUTSTANDING_SENT_PACKETS);
    RETURN_STRING_LITERAL(QUIC_TOO_MANY_OUTSTANDING_RECEIVED_PACKETS);
    RETURN_STRING_LITERAL(QUIC_CONNECTION_CANCELLED);
    RETURN_STRING_LITERAL(QUIC_BAD_PACKET_LOSS_RATE);
    RETURN_STRING_LITERAL(QUIC_PUBLIC_RESETS_POST_HANDSHAKE);
    RETURN_STRING_LITERAL(QUIC_FAILED_TO_SERIALIZE_PACKET);
    RETURN_STRING_LITERAL(QUIC_TOO_MANY_AVAILABLE_STREAMS);
    RETURN_STRING_LITERAL(QUIC_UNENCRYPTED_FEC_DATA);
    RETURN_STRING_LITERAL(QUIC_BAD_MULTIPATH_FLAG);
    RETURN_STRING_LITERAL(QUIC_IP_ADDRESS_CHANGED);
    RETURN_STRING_LITERAL(QUIC_CONNECTION_MIGRATION_NO_MIGRATABLE_STREAMS);
    RETURN_STRING_LITERAL(QUIC_CONNECTION_MIGRATION_TOO_MANY_CHANGES);
    RETURN_STRING_LITERAL(QUIC_CONNECTION_MIGRATION_NO_NEW_NETWORK);
    RETURN_STRING_LITERAL(QUIC_CONNECTION_MIGRATION_NON_MIGRATABLE_STREAM);
    RETURN_STRING_LITERAL(QUIC_TOO_MANY_RTOS);
    RETURN_STRING_LITERAL(QUIC_ATTEMPT_TO_SEND_UNENCRYPTED_STREAM_DATA);
    RETURN_STRING_LITERAL(QUIC_MAYBE_CORRUPTED_MEMORY);
    RETURN_STRING_LITERAL(QUIC_CRYPTO_CHLO_TOO_LARGE);
    RETURN_STRING_LITERAL(QUIC_MULTIPATH_PATH_DOES_NOT_EXIST);
    RETURN_STRING_LITERAL(QUIC_MULTIPATH_PATH_NOT_ACTIVE);
    RETURN_STRING_LITERAL(QUIC_TOO_MANY_STREAM_DATA_INTERVALS);
    RETURN_STRING_LITERAL(QUIC_STREAM_SEQUENCER_INVALID_STATE);
    RETURN_STRING_LITERAL(QUIC_TOO_MANY_SESSIONS_ON_SERVER);
    RETURN_STRING_LITERAL(QUIC_STREAM_LENGTH_OVERFLOW);
    RETURN_STRING_LITERAL(QUIC_CONNECTION_MIGRATION_DISABLED_BY_CONFIG);
    RETURN_STRING_LITERAL(QUIC_CONNECTION_MIGRATION_INTERNAL_ERROR);
    RETURN_STRING_LITERAL(QUIC_INVALID_MAX_DATA_FRAME_DATA);
    RETURN_STRING_LITERAL(QUIC_INVALID_MAX_STREAM_DATA_FRAME_DATA);
    RETURN_STRING_LITERAL(QUIC_INVALID_STREAM_BLOCKED_DATA);
    RETURN_STRING_LITERAL(QUIC_MAX_STREAMS_DATA);
    RETURN_STRING_LITERAL(QUIC_STREAMS_BLOCKED_DATA);
    RETURN_STRING_LITERAL(QUIC_INVALID_NEW_CONNECTION_ID_DATA);
    RETURN_STRING_LITERAL(QUIC_INVALID_RETIRE_CONNECTION_ID_DATA);
    RETURN_STRING_LITERAL(QUIC_INVALID_STOP_SENDING_FRAME_DATA);
    RETURN_STRING_LITERAL(QUIC_INVALID_PATH_CHALLENGE_DATA);
    RETURN_STRING_LITERAL(QUIC_INVALID_PATH_RESPONSE_DATA);
    RETURN_STRING_LITERAL(QUIC_CONNECTION_MIGRATION_HANDSHAKE_UNCONFIRMED);
    RETURN_STRING_LITERAL(QUIC_INVALID_MESSAGE_DATA);
    RETURN_STRING_LITERAL(IETF_QUIC_PROTOCOL_VIOLATION);
    RETURN_STRING_LITERAL(QUIC_INVALID_NEW_TOKEN);
    RETURN_STRING_LITERAL(QUIC_DATA_RECEIVED_ON_WRITE_UNIDIRECTIONAL_STREAM);
    RETURN_STRING_LITERAL(QUIC_TRY_TO_WRITE_DATA_ON_READ_UNIDIRECTIONAL_STREAM);
    RETURN_STRING_LITERAL(QUIC_STREAMS_BLOCKED_ERROR);
    RETURN_STRING_LITERAL(QUIC_MAX_STREAMS_ERROR);
    RETURN_STRING_LITERAL(QUIC_HTTP_DECODER_ERROR);
    RETURN_STRING_LITERAL(QUIC_STALE_CONNECTION_CANCELLED);
    RETURN_STRING_LITERAL(QUIC_IETF_GQUIC_ERROR_MISSING);
    RETURN_STRING_LITERAL(
        QUIC_WINDOW_UPDATE_RECEIVED_ON_READ_UNIDIRECTIONAL_STREAM);
    RETURN_STRING_LITERAL(QUIC_TOO_MANY_BUFFERED_CONTROL_FRAMES);
    RETURN_STRING_LITERAL(QUIC_TRANSPORT_INVALID_CLIENT_INDICATION);
    RETURN_STRING_LITERAL(QUIC_QPACK_DECOMPRESSION_FAILED);
    RETURN_STRING_LITERAL(QUIC_QPACK_ENCODER_STREAM_ERROR);
    RETURN_STRING_LITERAL(QUIC_QPACK_DECODER_STREAM_ERROR);
    RETURN_STRING_LITERAL(QUIC_STREAM_DATA_BEYOND_CLOSE_OFFSET);
    RETURN_STRING_LITERAL(QUIC_STREAM_MULTIPLE_OFFSET);
    RETURN_STRING_LITERAL(QUIC_HTTP_FRAME_TOO_LARGE);
    RETURN_STRING_LITERAL(QUIC_HTTP_FRAME_ERROR);
    RETURN_STRING_LITERAL(QUIC_HTTP_FRAME_UNEXPECTED_ON_SPDY_STREAM);
    RETURN_STRING_LITERAL(QUIC_HTTP_FRAME_UNEXPECTED_ON_CONTROL_STREAM);
    RETURN_STRING_LITERAL(QUIC_HTTP_INVALID_FRAME_SEQUENCE_ON_SPDY_STREAM);
    RETURN_STRING_LITERAL(QUIC_HTTP_INVALID_FRAME_SEQUENCE_ON_CONTROL_STREAM);
    RETURN_STRING_LITERAL(QUIC_HTTP_DUPLICATE_UNIDIRECTIONAL_STREAM);
    RETURN_STRING_LITERAL(QUIC_HTTP_SERVER_INITIATED_BIDIRECTIONAL_STREAM);
    RETURN_STRING_LITERAL(QUIC_HTTP_STREAM_WRONG_DIRECTION);
    RETURN_STRING_LITERAL(QUIC_HTTP_CLOSED_CRITICAL_STREAM);
    RETURN_STRING_LITERAL(QUIC_HTTP_MISSING_SETTINGS_FRAME);
    RETURN_STRING_LITERAL(QUIC_HTTP_DUPLICATE_SETTING_IDENTIFIER);
    RETURN_STRING_LITERAL(QUIC_HTTP_INVALID_MAX_PUSH_ID);
    RETURN_STRING_LITERAL(QUIC_HPACK_INDEX_VARINT_ERROR);
    RETURN_STRING_LITERAL(QUIC_HPACK_NAME_LENGTH_VARINT_ERROR);
    RETURN_STRING_LITERAL(QUIC_HPACK_VALUE_LENGTH_VARINT_ERROR);
    RETURN_STRING_LITERAL(QUIC_HPACK_NAME_TOO_LONG);
    RETURN_STRING_LITERAL(QUIC_HPACK_VALUE_TOO_LONG);
    RETURN_STRING_LITERAL(QUIC_HPACK_NAME_HUFFMAN_ERROR);
    RETURN_STRING_LITERAL(QUIC_HPACK_VALUE_HUFFMAN_ERROR);
    RETURN_STRING_LITERAL(QUIC_HPACK_MISSING_DYNAMIC_TABLE_SIZE_UPDATE);
    RETURN_STRING_LITERAL(QUIC_HPACK_INVALID_INDEX);
    RETURN_STRING_LITERAL(QUIC_HPACK_INVALID_NAME_INDEX);
    RETURN_STRING_LITERAL(QUIC_HPACK_DYNAMIC_TABLE_SIZE_UPDATE_NOT_ALLOWED);
    RETURN_STRING_LITERAL(
        QUIC_HPACK_INITIAL_TABLE_SIZE_UPDATE_IS_ABOVE_LOW_WATER_MARK);
    RETURN_STRING_LITERAL(
        QUIC_HPACK_TABLE_SIZE_UPDATE_IS_ABOVE_ACKNOWLEDGED_SETTING);
    RETURN_STRING_LITERAL(QUIC_HPACK_TRUNCATED_BLOCK);
    RETURN_STRING_LITERAL(QUIC_HPACK_FRAGMENT_TOO_LONG);
    RETURN_STRING_LITERAL(QUIC_HPACK_COMPRESSED_HEADER_SIZE_EXCEEDS_LIMIT);

    RETURN_STRING_LITERAL(QUIC_LAST_ERROR);
    // Intentionally have no default case, so we'll break the build
    // if we add errors and don't put them here.
  }
  // Return a default value so that we return this when |error| doesn't match
  // any of the QuicErrorCodes. This can happen when the ConnectionClose
  // frame sent by the peer (attacker) has invalid error code.
  return "INVALID_ERROR_CODE";
}

std::string QuicIetfTransportErrorCodeString(QuicIetfTransportErrorCodes c) {
  if (static_cast<uint64_t>(c) >= 0xff00u) {
    return quiche::QuicheStrCat("Private(", static_cast<uint64_t>(c), ")");
  }
  if (c >= CRYPTO_ERROR_FIRST && c <= CRYPTO_ERROR_LAST) {
    const int tls_error = static_cast<int>(c - CRYPTO_ERROR_FIRST);
    const char* tls_error_description = SSL_alert_desc_string_long(tls_error);
    if (strcmp("unknown", tls_error_description) != 0) {
      return quiche::QuicheStrCat("CRYPTO_ERROR(", tls_error_description, ")");
    }
    return quiche::QuicheStrCat("CRYPTO_ERROR(unknown(", tls_error, "))");
  }

  switch (c) {
    RETURN_STRING_LITERAL(NO_IETF_QUIC_ERROR);
    RETURN_STRING_LITERAL(INTERNAL_ERROR);
    RETURN_STRING_LITERAL(SERVER_BUSY_ERROR);
    RETURN_STRING_LITERAL(FLOW_CONTROL_ERROR);
    RETURN_STRING_LITERAL(STREAM_LIMIT_ERROR);
    RETURN_STRING_LITERAL(STREAM_STATE_ERROR);
    RETURN_STRING_LITERAL(FINAL_SIZE_ERROR);
    RETURN_STRING_LITERAL(FRAME_ENCODING_ERROR);
    RETURN_STRING_LITERAL(TRANSPORT_PARAMETER_ERROR);
    RETURN_STRING_LITERAL(CONNECTION_ID_LIMIT_ERROR);
    RETURN_STRING_LITERAL(PROTOCOL_VIOLATION);
    RETURN_STRING_LITERAL(INVALID_TOKEN);
    RETURN_STRING_LITERAL(CRYPTO_BUFFER_EXCEEDED);
    // CRYPTO_ERROR is handled in the if before this switch, these cases do not
    // change behavior and are only here to make the compiler happy.
    case CRYPTO_ERROR_FIRST:
    case CRYPTO_ERROR_LAST:
      DCHECK(false) << "Unexpected error " << static_cast<uint64_t>(c);
      break;
  }

  return quiche::QuicheStrCat("Unknown(", static_cast<uint64_t>(c), ")");
}

std::ostream& operator<<(std::ostream& os,
                         const QuicIetfTransportErrorCodes& c) {
  os << QuicIetfTransportErrorCodeString(c);
  return os;
}

QuicErrorCodeToIetfMapping QuicErrorCodeToTransportErrorCode(
    QuicErrorCode error) {
  switch (error) {
    case QUIC_NO_ERROR:
      return {true, static_cast<uint64_t>(NO_IETF_QUIC_ERROR)};
    case QUIC_INTERNAL_ERROR:
      return {true, static_cast<uint64_t>(INTERNAL_ERROR)};
    case QUIC_STREAM_DATA_AFTER_TERMINATION:
      return {true, static_cast<uint64_t>(INTERNAL_ERROR)};
    case QUIC_INVALID_PACKET_HEADER:
      return {true, static_cast<uint64_t>(FRAME_ENCODING_ERROR)};
    case QUIC_INVALID_FRAME_DATA:
      return {true, static_cast<uint64_t>(FRAME_ENCODING_ERROR)};
    case QUIC_MISSING_PAYLOAD:
      return {true, static_cast<uint64_t>(FRAME_ENCODING_ERROR)};
    case QUIC_INVALID_FEC_DATA:
      return {true, static_cast<uint64_t>(INTERNAL_ERROR)};
    case QUIC_INVALID_STREAM_DATA:
      return {true, static_cast<uint64_t>(FRAME_ENCODING_ERROR)};
    case QUIC_OVERLAPPING_STREAM_DATA:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_UNENCRYPTED_STREAM_DATA:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_ATTEMPT_TO_SEND_UNENCRYPTED_STREAM_DATA:
      return {true, static_cast<uint64_t>(INTERNAL_ERROR)};
    case QUIC_MAYBE_CORRUPTED_MEMORY:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_UNENCRYPTED_FEC_DATA:
      return {true, static_cast<uint64_t>(INTERNAL_ERROR)};
    case QUIC_INVALID_RST_STREAM_DATA:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_INVALID_CONNECTION_CLOSE_DATA:
      return {true, static_cast<uint64_t>(FRAME_ENCODING_ERROR)};
    case QUIC_INVALID_GOAWAY_DATA:
      return {true, static_cast<uint64_t>(FRAME_ENCODING_ERROR)};
    case QUIC_INVALID_WINDOW_UPDATE_DATA:
      return {true, static_cast<uint64_t>(FRAME_ENCODING_ERROR)};
    case QUIC_INVALID_BLOCKED_DATA:
      return {true, static_cast<uint64_t>(FRAME_ENCODING_ERROR)};
    case QUIC_INVALID_STOP_WAITING_DATA:
      return {true, static_cast<uint64_t>(FRAME_ENCODING_ERROR)};
    case QUIC_INVALID_PATH_CLOSE_DATA:
      return {true, static_cast<uint64_t>(INTERNAL_ERROR)};
    case QUIC_INVALID_ACK_DATA:
      return {true, static_cast<uint64_t>(FRAME_ENCODING_ERROR)};
    case QUIC_INVALID_MESSAGE_DATA:
      return {true, static_cast<uint64_t>(FRAME_ENCODING_ERROR)};
    case QUIC_INVALID_VERSION_NEGOTIATION_PACKET:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_INVALID_PUBLIC_RST_PACKET:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_DECRYPTION_FAILURE:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_ENCRYPTION_FAILURE:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_PACKET_TOO_LARGE:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_PEER_GOING_AWAY:
      return {true, static_cast<uint64_t>(INTERNAL_ERROR)};
    case QUIC_INVALID_STREAM_ID:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_INVALID_PRIORITY:
      return {true, static_cast<uint64_t>(INTERNAL_ERROR)};
    case QUIC_TOO_MANY_OPEN_STREAMS:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_TOO_MANY_AVAILABLE_STREAMS:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_PUBLIC_RESET:
      return {true, static_cast<uint64_t>(INTERNAL_ERROR)};
    case QUIC_INVALID_VERSION:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_INVALID_HEADER_ID:
      return {true, static_cast<uint64_t>(INTERNAL_ERROR)};
    case QUIC_INVALID_NEGOTIATED_VALUE:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_DECOMPRESSION_FAILURE:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_NETWORK_IDLE_TIMEOUT:
      return {true, static_cast<uint64_t>(NO_IETF_QUIC_ERROR)};
    case QUIC_HANDSHAKE_TIMEOUT:
      return {true, static_cast<uint64_t>(NO_IETF_QUIC_ERROR)};
    case QUIC_ERROR_MIGRATING_ADDRESS:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_ERROR_MIGRATING_PORT:
      return {true, static_cast<uint64_t>(INTERNAL_ERROR)};
    case QUIC_PACKET_WRITE_ERROR:
      return {true, static_cast<uint64_t>(INTERNAL_ERROR)};
    case QUIC_PACKET_READ_ERROR:
      return {true, static_cast<uint64_t>(INTERNAL_ERROR)};
    case QUIC_EMPTY_STREAM_FRAME_NO_FIN:
      return {true, static_cast<uint64_t>(FRAME_ENCODING_ERROR)};
    case QUIC_INVALID_HEADERS_STREAM_DATA:
      return {true, static_cast<uint64_t>(INTERNAL_ERROR)};
    case QUIC_HEADERS_STREAM_DATA_DECOMPRESS_FAILURE:
      return {true, static_cast<uint64_t>(INTERNAL_ERROR)};
    case QUIC_FLOW_CONTROL_RECEIVED_TOO_MUCH_DATA:
      return {true, static_cast<uint64_t>(FLOW_CONTROL_ERROR)};
    case QUIC_FLOW_CONTROL_SENT_TOO_MUCH_DATA:
      return {true, static_cast<uint64_t>(INTERNAL_ERROR)};
    case QUIC_FLOW_CONTROL_INVALID_WINDOW:
      return {true, static_cast<uint64_t>(FLOW_CONTROL_ERROR)};
    case QUIC_CONNECTION_IP_POOLED:
      return {true, static_cast<uint64_t>(INTERNAL_ERROR)};
    case QUIC_TOO_MANY_OUTSTANDING_SENT_PACKETS:
      return {true, static_cast<uint64_t>(INTERNAL_ERROR)};
    case QUIC_TOO_MANY_OUTSTANDING_RECEIVED_PACKETS:
      return {true, static_cast<uint64_t>(INTERNAL_ERROR)};
    case QUIC_CONNECTION_CANCELLED:
      return {true, static_cast<uint64_t>(NO_IETF_QUIC_ERROR)};
    case QUIC_BAD_PACKET_LOSS_RATE:
      return {true, static_cast<uint64_t>(INTERNAL_ERROR)};
    case QUIC_PUBLIC_RESETS_POST_HANDSHAKE:
      return {true, static_cast<uint64_t>(INTERNAL_ERROR)};
    case QUIC_FAILED_TO_SERIALIZE_PACKET:
      return {true, static_cast<uint64_t>(INTERNAL_ERROR)};
    case QUIC_TOO_MANY_RTOS:
      return {true, static_cast<uint64_t>(NO_IETF_QUIC_ERROR)};
    case QUIC_HANDSHAKE_FAILED:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_CRYPTO_TAGS_OUT_OF_ORDER:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_CRYPTO_TOO_MANY_ENTRIES:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_CRYPTO_INVALID_VALUE_LENGTH:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_CRYPTO_MESSAGE_AFTER_HANDSHAKE_COMPLETE:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_INVALID_CRYPTO_MESSAGE_TYPE:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_INVALID_CRYPTO_MESSAGE_PARAMETER:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_INVALID_CHANNEL_ID_SIGNATURE:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_CRYPTO_MESSAGE_PARAMETER_NOT_FOUND:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_CRYPTO_MESSAGE_PARAMETER_NO_OVERLAP:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_CRYPTO_MESSAGE_INDEX_NOT_FOUND:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_UNSUPPORTED_PROOF_DEMAND:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_CRYPTO_INTERNAL_ERROR:
      return {true, static_cast<uint64_t>(INTERNAL_ERROR)};
    case QUIC_CRYPTO_VERSION_NOT_SUPPORTED:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_CRYPTO_NO_SUPPORT:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_CRYPTO_TOO_MANY_REJECTS:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_PROOF_INVALID:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_CRYPTO_DUPLICATE_TAG:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_CRYPTO_ENCRYPTION_LEVEL_INCORRECT:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_CRYPTO_SERVER_CONFIG_EXPIRED:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_CRYPTO_SYMMETRIC_KEY_SETUP_FAILED:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_CRYPTO_MESSAGE_WHILE_VALIDATING_CLIENT_HELLO:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_CRYPTO_UPDATE_BEFORE_HANDSHAKE_COMPLETE:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_CRYPTO_CHLO_TOO_LARGE:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_VERSION_NEGOTIATION_MISMATCH:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_BAD_MULTIPATH_FLAG:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_MULTIPATH_PATH_DOES_NOT_EXIST:
      return {true, static_cast<uint64_t>(INTERNAL_ERROR)};
    case QUIC_MULTIPATH_PATH_NOT_ACTIVE:
      return {true, static_cast<uint64_t>(INTERNAL_ERROR)};
    case QUIC_IP_ADDRESS_CHANGED:
      return {true, static_cast<uint64_t>(INTERNAL_ERROR)};
    case QUIC_CONNECTION_MIGRATION_NO_MIGRATABLE_STREAMS:
      return {true, static_cast<uint64_t>(INTERNAL_ERROR)};
    case QUIC_CONNECTION_MIGRATION_TOO_MANY_CHANGES:
      return {true, static_cast<uint64_t>(INTERNAL_ERROR)};
    case QUIC_CONNECTION_MIGRATION_NO_NEW_NETWORK:
      return {true, static_cast<uint64_t>(INTERNAL_ERROR)};
    case QUIC_CONNECTION_MIGRATION_NON_MIGRATABLE_STREAM:
      return {true, static_cast<uint64_t>(INTERNAL_ERROR)};
    case QUIC_CONNECTION_MIGRATION_DISABLED_BY_CONFIG:
      return {true, static_cast<uint64_t>(INTERNAL_ERROR)};
    case QUIC_CONNECTION_MIGRATION_INTERNAL_ERROR:
      return {true, static_cast<uint64_t>(INTERNAL_ERROR)};
    case QUIC_CONNECTION_MIGRATION_HANDSHAKE_UNCONFIRMED:
      return {true, static_cast<uint64_t>(INTERNAL_ERROR)};
    case QUIC_TOO_MANY_STREAM_DATA_INTERVALS:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_STREAM_SEQUENCER_INVALID_STATE:
      return {true, static_cast<uint64_t>(INTERNAL_ERROR)};
    case QUIC_TOO_MANY_SESSIONS_ON_SERVER:
      return {true, static_cast<uint64_t>(INTERNAL_ERROR)};
    case QUIC_STREAM_LENGTH_OVERFLOW:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_INVALID_MAX_DATA_FRAME_DATA:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_INVALID_MAX_STREAM_DATA_FRAME_DATA:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_MAX_STREAMS_DATA:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_STREAMS_BLOCKED_DATA:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_INVALID_STREAM_BLOCKED_DATA:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_INVALID_NEW_CONNECTION_ID_DATA:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_INVALID_STOP_SENDING_FRAME_DATA:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_INVALID_PATH_CHALLENGE_DATA:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_INVALID_PATH_RESPONSE_DATA:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case IETF_QUIC_PROTOCOL_VIOLATION:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_INVALID_NEW_TOKEN:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_DATA_RECEIVED_ON_WRITE_UNIDIRECTIONAL_STREAM:
      return {true, static_cast<uint64_t>(STREAM_STATE_ERROR)};
    case QUIC_TRY_TO_WRITE_DATA_ON_READ_UNIDIRECTIONAL_STREAM:
      return {true, static_cast<uint64_t>(INTERNAL_ERROR)};
    case QUIC_INVALID_RETIRE_CONNECTION_ID_DATA:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_STREAMS_BLOCKED_ERROR:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_MAX_STREAMS_ERROR:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_HTTP_DECODER_ERROR:
      return {true, static_cast<uint64_t>(INTERNAL_ERROR)};
    case QUIC_STALE_CONNECTION_CANCELLED:
      return {true, static_cast<uint64_t>(INTERNAL_ERROR)};
    case QUIC_IETF_GQUIC_ERROR_MISSING:
      return {true, static_cast<uint64_t>(INTERNAL_ERROR)};
    case QUIC_WINDOW_UPDATE_RECEIVED_ON_READ_UNIDIRECTIONAL_STREAM:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_TOO_MANY_BUFFERED_CONTROL_FRAMES:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_TRANSPORT_INVALID_CLIENT_INDICATION:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_QPACK_DECOMPRESSION_FAILED:
      return {false, static_cast<uint64_t>(
                         QuicHttpQpackErrorCode::DECOMPRESSION_FAILED)};
    case QUIC_QPACK_ENCODER_STREAM_ERROR:
      return {false, static_cast<uint64_t>(
                         QuicHttpQpackErrorCode::ENCODER_STREAM_ERROR)};
    case QUIC_QPACK_DECODER_STREAM_ERROR:
      return {false, static_cast<uint64_t>(
                         QuicHttpQpackErrorCode::DECODER_STREAM_ERROR)};
    case QUIC_STREAM_DATA_BEYOND_CLOSE_OFFSET:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_STREAM_MULTIPLE_OFFSET:
      return {true, static_cast<uint64_t>(PROTOCOL_VIOLATION)};
    case QUIC_HTTP_FRAME_TOO_LARGE:
      return {false, static_cast<uint64_t>(QuicHttp3ErrorCode::EXCESSIVE_LOAD)};
    case QUIC_HTTP_FRAME_ERROR:
      return {false, static_cast<uint64_t>(QuicHttp3ErrorCode::FRAME_ERROR)};
    case QUIC_HTTP_FRAME_UNEXPECTED_ON_SPDY_STREAM:
      return {false,
              static_cast<uint64_t>(QuicHttp3ErrorCode::FRAME_UNEXPECTED)};
    case QUIC_HTTP_FRAME_UNEXPECTED_ON_CONTROL_STREAM:
      return {false,
              static_cast<uint64_t>(QuicHttp3ErrorCode::FRAME_UNEXPECTED)};
    case QUIC_HTTP_INVALID_FRAME_SEQUENCE_ON_SPDY_STREAM:
      return {false,
              static_cast<uint64_t>(QuicHttp3ErrorCode::FRAME_UNEXPECTED)};
    case QUIC_HTTP_INVALID_FRAME_SEQUENCE_ON_CONTROL_STREAM:
      return {false,
              static_cast<uint64_t>(QuicHttp3ErrorCode::FRAME_UNEXPECTED)};
    case QUIC_HTTP_DUPLICATE_UNIDIRECTIONAL_STREAM:
      return {false,
              static_cast<uint64_t>(QuicHttp3ErrorCode::STREAM_CREATION_ERROR)};
    case QUIC_HTTP_SERVER_INITIATED_BIDIRECTIONAL_STREAM:
      return {false,
              static_cast<uint64_t>(QuicHttp3ErrorCode::STREAM_CREATION_ERROR)};
    case QUIC_HTTP_STREAM_WRONG_DIRECTION:
      return {true, static_cast<uint64_t>(STREAM_STATE_ERROR)};
    case QUIC_HTTP_CLOSED_CRITICAL_STREAM:
      return {false, static_cast<uint64_t>(
                         QuicHttp3ErrorCode::CLOSED_CRITICAL_STREAM)};
    case QUIC_HTTP_MISSING_SETTINGS_FRAME:
      return {false,
              static_cast<uint64_t>(QuicHttp3ErrorCode::MISSING_SETTINGS)};
    case QUIC_HTTP_DUPLICATE_SETTING_IDENTIFIER:
      return {false, static_cast<uint64_t>(QuicHttp3ErrorCode::SETTINGS_ERROR)};
    case QUIC_HTTP_INVALID_MAX_PUSH_ID:
      return {false, static_cast<uint64_t>(QuicHttp3ErrorCode::ID_ERROR)};
    case QUIC_HPACK_INDEX_VARINT_ERROR:
      return {true, static_cast<uint64_t>(INTERNAL_ERROR)};
    case QUIC_HPACK_NAME_LENGTH_VARINT_ERROR:
      return {true, static_cast<uint64_t>(INTERNAL_ERROR)};
    case QUIC_HPACK_VALUE_LENGTH_VARINT_ERROR:
      return {true, static_cast<uint64_t>(INTERNAL_ERROR)};
    case QUIC_HPACK_NAME_TOO_LONG:
      return {true, static_cast<uint64_t>(INTERNAL_ERROR)};
    case QUIC_HPACK_VALUE_TOO_LONG:
      return {true, static_cast<uint64_t>(INTERNAL_ERROR)};
    case QUIC_HPACK_NAME_HUFFMAN_ERROR:
      return {true, static_cast<uint64_t>(INTERNAL_ERROR)};
    case QUIC_HPACK_VALUE_HUFFMAN_ERROR:
      return {true, static_cast<uint64_t>(INTERNAL_ERROR)};
    case QUIC_HPACK_MISSING_DYNAMIC_TABLE_SIZE_UPDATE:
      return {true, static_cast<uint64_t>(INTERNAL_ERROR)};
    case QUIC_HPACK_INVALID_INDEX:
      return {true, static_cast<uint64_t>(INTERNAL_ERROR)};
    case QUIC_HPACK_INVALID_NAME_INDEX:
      return {true, static_cast<uint64_t>(INTERNAL_ERROR)};
    case QUIC_HPACK_DYNAMIC_TABLE_SIZE_UPDATE_NOT_ALLOWED:
      return {true, static_cast<uint64_t>(INTERNAL_ERROR)};
    case QUIC_HPACK_INITIAL_TABLE_SIZE_UPDATE_IS_ABOVE_LOW_WATER_MARK:
      return {true, static_cast<uint64_t>(INTERNAL_ERROR)};
    case QUIC_HPACK_TABLE_SIZE_UPDATE_IS_ABOVE_ACKNOWLEDGED_SETTING:
      return {true, static_cast<uint64_t>(INTERNAL_ERROR)};
    case QUIC_HPACK_TRUNCATED_BLOCK:
      return {true, static_cast<uint64_t>(INTERNAL_ERROR)};
    case QUIC_HPACK_FRAGMENT_TOO_LONG:
      return {true, static_cast<uint64_t>(INTERNAL_ERROR)};
    case QUIC_HPACK_COMPRESSED_HEADER_SIZE_EXCEEDS_LIMIT:
      return {true, static_cast<uint64_t>(INTERNAL_ERROR)};
    case QUIC_LAST_ERROR:
      return {false, static_cast<uint64_t>(QUIC_LAST_ERROR)};
  }
  // This function should not be called with unknown error code.
  return {true, static_cast<uint64_t>(INTERNAL_ERROR)};
}

// Convert a QuicRstStreamErrorCode to an application error code to be used in
// an IETF QUIC RESET_STREAM frame
uint64_t RstStreamErrorCodeToIetfResetStreamErrorCode(
    QuicRstStreamErrorCode rst_stream_error_code) {
  switch (rst_stream_error_code) {
    case QUIC_STREAM_NO_ERROR:
      return static_cast<uint64_t>(QuicHttp3ErrorCode::HTTP3_NO_ERROR);
    case QUIC_ERROR_PROCESSING_STREAM:
      return static_cast<uint64_t>(QuicHttp3ErrorCode::GENERAL_PROTOCOL_ERROR);
    case QUIC_MULTIPLE_TERMINATION_OFFSETS:
      return static_cast<uint64_t>(QuicHttp3ErrorCode::GENERAL_PROTOCOL_ERROR);
    case QUIC_BAD_APPLICATION_PAYLOAD:
      return static_cast<uint64_t>(QuicHttp3ErrorCode::GENERAL_PROTOCOL_ERROR);
    case QUIC_STREAM_CONNECTION_ERROR:
      return static_cast<uint64_t>(QuicHttp3ErrorCode::INTERNAL_ERROR);
    case QUIC_STREAM_PEER_GOING_AWAY:
      return static_cast<uint64_t>(QuicHttp3ErrorCode::GENERAL_PROTOCOL_ERROR);
    case QUIC_STREAM_CANCELLED:
      return static_cast<uint64_t>(QuicHttp3ErrorCode::REQUEST_CANCELLED);
    case QUIC_RST_ACKNOWLEDGEMENT:
      return static_cast<uint64_t>(QuicHttp3ErrorCode::HTTP3_NO_ERROR);
    case QUIC_REFUSED_STREAM:
      return static_cast<uint64_t>(QuicHttp3ErrorCode::ID_ERROR);
    case QUIC_INVALID_PROMISE_URL:
      return static_cast<uint64_t>(QuicHttp3ErrorCode::STREAM_CREATION_ERROR);
    case QUIC_UNAUTHORIZED_PROMISE_URL:
      return static_cast<uint64_t>(QuicHttp3ErrorCode::STREAM_CREATION_ERROR);
    case QUIC_DUPLICATE_PROMISE_URL:
      return static_cast<uint64_t>(QuicHttp3ErrorCode::STREAM_CREATION_ERROR);
    case QUIC_PROMISE_VARY_MISMATCH:
      return static_cast<uint64_t>(QuicHttp3ErrorCode::REQUEST_CANCELLED);
    case QUIC_INVALID_PROMISE_METHOD:
      return static_cast<uint64_t>(QuicHttp3ErrorCode::STREAM_CREATION_ERROR);
    case QUIC_PUSH_STREAM_TIMED_OUT:
      return static_cast<uint64_t>(QuicHttp3ErrorCode::REQUEST_CANCELLED);
    case QUIC_HEADERS_TOO_LARGE:
      return static_cast<uint64_t>(QuicHttp3ErrorCode::EXCESSIVE_LOAD);
    case QUIC_STREAM_TTL_EXPIRED:
      return static_cast<uint64_t>(QuicHttp3ErrorCode::REQUEST_CANCELLED);
    case QUIC_DATA_AFTER_CLOSE_OFFSET:
      return static_cast<uint64_t>(QuicHttp3ErrorCode::GENERAL_PROTOCOL_ERROR);
    case QUIC_STREAM_GENERAL_PROTOCOL_ERROR:
      return static_cast<uint64_t>(QuicHttp3ErrorCode::GENERAL_PROTOCOL_ERROR);
    case QUIC_STREAM_INTERNAL_ERROR:
      return static_cast<uint64_t>(QuicHttp3ErrorCode::INTERNAL_ERROR);
    case QUIC_STREAM_STREAM_CREATION_ERROR:
      return static_cast<uint64_t>(QuicHttp3ErrorCode::STREAM_CREATION_ERROR);
    case QUIC_STREAM_CLOSED_CRITICAL_STREAM:
      return static_cast<uint64_t>(QuicHttp3ErrorCode::CLOSED_CRITICAL_STREAM);
    case QUIC_STREAM_FRAME_UNEXPECTED:
      return static_cast<uint64_t>(QuicHttp3ErrorCode::FRAME_UNEXPECTED);
    case QUIC_STREAM_FRAME_ERROR:
      return static_cast<uint64_t>(QuicHttp3ErrorCode::FRAME_ERROR);
    case QUIC_STREAM_EXCESSIVE_LOAD:
      return static_cast<uint64_t>(QuicHttp3ErrorCode::EXCESSIVE_LOAD);
    case QUIC_STREAM_ID_ERROR:
      return static_cast<uint64_t>(QuicHttp3ErrorCode::ID_ERROR);
    case QUIC_STREAM_SETTINGS_ERROR:
      return static_cast<uint64_t>(QuicHttp3ErrorCode::SETTINGS_ERROR);
    case QUIC_STREAM_MISSING_SETTINGS:
      return static_cast<uint64_t>(QuicHttp3ErrorCode::MISSING_SETTINGS);
    case QUIC_STREAM_REQUEST_REJECTED:
      return static_cast<uint64_t>(QuicHttp3ErrorCode::REQUEST_REJECTED);
    case QUIC_STREAM_REQUEST_INCOMPLETE:
      return static_cast<uint64_t>(QuicHttp3ErrorCode::REQUEST_INCOMPLETE);
    case QUIC_STREAM_CONNECT_ERROR:
      return static_cast<uint64_t>(QuicHttp3ErrorCode::CONNECT_ERROR);
    case QUIC_STREAM_VERSION_FALLBACK:
      return static_cast<uint64_t>(QuicHttp3ErrorCode::VERSION_FALLBACK);
    case QUIC_STREAM_DECOMPRESSION_FAILED:
      return static_cast<uint64_t>(
          QuicHttpQpackErrorCode::DECOMPRESSION_FAILED);
    case QUIC_STREAM_ENCODER_STREAM_ERROR:
      return static_cast<uint64_t>(
          QuicHttpQpackErrorCode::ENCODER_STREAM_ERROR);
    case QUIC_STREAM_DECODER_STREAM_ERROR:
      return static_cast<uint64_t>(
          QuicHttpQpackErrorCode::DECODER_STREAM_ERROR);
    case QUIC_STREAM_UNKNOWN_APPLICATION_ERRROR_CODE:
      return static_cast<uint64_t>(QuicHttp3ErrorCode::INTERNAL_ERROR);
    case QUIC_STREAM_LAST_ERROR:
      return static_cast<uint64_t>(QuicHttp3ErrorCode::INTERNAL_ERROR);
  }
  return static_cast<uint64_t>(QuicHttp3ErrorCode::INTERNAL_ERROR);
}

// Convert the application error code of an IETF QUIC RESET_STREAM frame
// to QuicRstStreamErrorCode.
QuicRstStreamErrorCode IetfResetStreamErrorCodeToRstStreamErrorCode(
    uint64_t ietf_error_code) {
  switch (ietf_error_code) {
    case static_cast<uint64_t>(QuicHttp3ErrorCode::HTTP3_NO_ERROR):
      return QUIC_STREAM_NO_ERROR;
    case static_cast<uint64_t>(QuicHttp3ErrorCode::GENERAL_PROTOCOL_ERROR):
      return QUIC_STREAM_GENERAL_PROTOCOL_ERROR;
    case static_cast<uint64_t>(QuicHttp3ErrorCode::INTERNAL_ERROR):
      return QUIC_STREAM_INTERNAL_ERROR;
    case static_cast<uint64_t>(QuicHttp3ErrorCode::STREAM_CREATION_ERROR):
      return QUIC_STREAM_STREAM_CREATION_ERROR;
    case static_cast<uint64_t>(QuicHttp3ErrorCode::CLOSED_CRITICAL_STREAM):
      return QUIC_STREAM_CLOSED_CRITICAL_STREAM;
    case static_cast<uint64_t>(QuicHttp3ErrorCode::FRAME_UNEXPECTED):
      return QUIC_STREAM_FRAME_UNEXPECTED;
    case static_cast<uint64_t>(QuicHttp3ErrorCode::FRAME_ERROR):
      return QUIC_STREAM_FRAME_ERROR;
    case static_cast<uint64_t>(QuicHttp3ErrorCode::EXCESSIVE_LOAD):
      return QUIC_STREAM_EXCESSIVE_LOAD;
    case static_cast<uint64_t>(QuicHttp3ErrorCode::ID_ERROR):
      return QUIC_STREAM_ID_ERROR;
    case static_cast<uint64_t>(QuicHttp3ErrorCode::SETTINGS_ERROR):
      return QUIC_STREAM_SETTINGS_ERROR;
    case static_cast<uint64_t>(QuicHttp3ErrorCode::MISSING_SETTINGS):
      return QUIC_STREAM_MISSING_SETTINGS;
    case static_cast<uint64_t>(QuicHttp3ErrorCode::REQUEST_REJECTED):
      return QUIC_STREAM_REQUEST_REJECTED;
    case static_cast<uint64_t>(QuicHttp3ErrorCode::REQUEST_CANCELLED):
      return QUIC_STREAM_CANCELLED;
    case static_cast<uint64_t>(QuicHttp3ErrorCode::REQUEST_INCOMPLETE):
      return QUIC_STREAM_REQUEST_INCOMPLETE;
    case static_cast<uint64_t>(QuicHttp3ErrorCode::CONNECT_ERROR):
      return QUIC_STREAM_CONNECT_ERROR;
    case static_cast<uint64_t>(QuicHttp3ErrorCode::VERSION_FALLBACK):
      return QUIC_STREAM_VERSION_FALLBACK;
    case static_cast<uint64_t>(QuicHttpQpackErrorCode::DECOMPRESSION_FAILED):
      return QUIC_STREAM_DECOMPRESSION_FAILED;
    case static_cast<uint64_t>(QuicHttpQpackErrorCode::ENCODER_STREAM_ERROR):
      return QUIC_STREAM_ENCODER_STREAM_ERROR;
    case static_cast<uint64_t>(QuicHttpQpackErrorCode::DECODER_STREAM_ERROR):
      return QUIC_STREAM_DECODER_STREAM_ERROR;
  }
  return QUIC_STREAM_UNKNOWN_APPLICATION_ERRROR_CODE;
}

#undef RETURN_STRING_LITERAL  // undef for jumbo builds

}  // namespace quic
